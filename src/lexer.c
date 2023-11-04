#include "index.h"

struct _lexer_t {
    char *code;
    list_t *token_list;
};

lexer_t *lexer_create(char *code) {
    lexer_t *self = allocate(sizeof(lexer_t));
    self->code = code;
    self->token_list = list_create();
    return self;
}

void
lexer_destroy(lexer_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        lexer_t *self = *self_ptr;
        free(self->code);
        list_destroy(&self->token_list, (list_item_free_fn_t *) token_free);
        free(self);
        *self_ptr = NULL;
    }
}

list_t *
lexer_token_list(lexer_t *self) {
    return self->token_list;
}

void
lexer_lex(lexer_t *self) {
    size_t index = 0;
    size_t code_length = strlen(self->code);
    char c = self->code[index];
    bool in_space_p = isspace(c);
    size_t max_buffer_length = 1024;
    char *buffer = allocate(max_buffer_length + 1);
    size_t buffer_length = 0;

    while(index < code_length) {
        c = self->code[index];

        if (in_space_p) {
            if (isspace(c)) {
            } else {
                buffer[0] = c;
                buffer[1] = '\0';
                buffer_length = 1;
            }
        } else {
            if (isspace(c)) {
                size_t start = index;
                size_t end = index + strlen(buffer);
                char *string = string_dup(buffer);
                token_t *token = token_word_create(string, start, end);
                list_push(self->token_list, token);
            } else {
                buffer[buffer_length] = c;
                buffer[buffer_length + 1] = '\0';
                buffer_length++;
            }
        }

        in_space_p = (isspace(c));
        index++;
    }

    size_t start = index;
    size_t end = index + strlen(buffer);
    char *string = string_dup(buffer);
    token_t *token = token_word_create(string, start, end);
    list_push(self->token_list, token);

    free(buffer);
}
