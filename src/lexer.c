#include "index.h"

typedef enum {
    IN_SPACE,
    IN_WORD,
    IN_DOUBLE_QUOTES,
} lexer_mode_t;

struct _lexer_t {
    list_t *token_list;
    char *code;
    size_t code_length;
    size_t index;
    lexer_mode_t mode;
    size_t max_string_length;
    char *string;
    size_t string_length;
};

lexer_t *lexer_create(char *code) {
    lexer_t *self = allocate(sizeof(lexer_t));
    self->token_list = list_create();
    self->code = code;
    self->code_length = strlen(code);
    self->index = 0;
    char c = self->code[0];
    self->mode = isspace(c) ? IN_SPACE : IN_WORD;
    self->max_string_length = 1024;
    self->string = allocate(self->max_string_length + 1);
    self->string_length = 0;
    return self;
}

void
lexer_destroy(lexer_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        lexer_t *self = *self_ptr;
        list_destroy(&self->token_list, (list_item_free_fn_t *) token_free);
        free(self->code);
        free(self->string);
        free(self);
        *self_ptr = NULL;
    }
}

list_t *
lexer_token_list(lexer_t *self) {
    return self->token_list;
}

void lexer_lex_ignore_space(lexer_t *self);
void lexer_lex_collect_char(lexer_t *self, char c);
void lexer_lex_collect_token(lexer_t *self);

void
lexer_lex(lexer_t *self) {
    while(self->index < self->code_length) {
        char c = self->code[self->index];

        if (!isspace(c))
            lexer_lex_collect_char(self, c);
        if (isspace(c) && self->mode == IN_SPACE)
            lexer_lex_ignore_space(self);
        if (isspace(c) && self->mode != IN_SPACE)
            lexer_lex_collect_token(self);

        self->index++;
        self->mode = isspace(c) ? IN_SPACE : IN_WORD;
    }

    lexer_lex_collect_token(self);
}

void
lexer_lex_ignore_space(lexer_t *self) {
    (void) self;
}

void
lexer_lex_collect_char(lexer_t *self, char c) {
    self->string[self->string_length] = c;
    self->string[self->string_length + 1] = '\0';
    self->string_length++;
}

void
lexer_lex_collect_token(lexer_t *self) {
    size_t start = self->index;
    size_t end = self->index + strlen(self->string);
    char *string = string_dup(self->string);
    token_t *token = token_word_create(string, start, end);
    list_push(self->token_list, token);

    self->string[0] = '\0';
    self->string_length = 0;
}
