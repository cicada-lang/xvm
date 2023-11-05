#include "index.h"

struct _lexer_t {
    list_t *token_list;
    const char *code;
    size_t code_length;
    size_t index;
    size_t max_string_length;
    char *string;
    size_t string_length;
};

lexer_t *lexer_create(const char *code) {
    lexer_t *self = allocate(sizeof(lexer_t));
    self->token_list = list_create();
    self->code = code;
    self->code_length = strlen(code);
    self->index = 0;
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
        free(self->string);
        free(self);
        *self_ptr = NULL;
    }
}

bool
lexer_finished_p(lexer_t *self) {
    return self->index < self->code_length;
}

char
lexer_current_char(lexer_t *self) {
    return self->code[self->index];
}

char
lexer_next_char(lexer_t *self) {
    return self->code[self->index + 1];
}

void
lexer_collect_char(lexer_t *self, char c) {
    self->string[self->string_length] = c;
    self->string[self->string_length + 1] = '\0';
    self->string_length++;
}

list_t *
lexer_token_list(lexer_t *self) {
    return self->token_list;
}

void lexer_lex_ignore_space(lexer_t *self);
void lexer_lex_ignore_comment(lexer_t *self);
void lexer_lex_double_qoutes(lexer_t *self);
void lexer_lex_word(lexer_t *self);

void
lexer_lex(lexer_t *self) {
    while (lexer_finished_p(self)) {
        char c = lexer_current_char(self);

        if (c == '\0')
            return;
        else if (c == '/' || lexer_next_char(self) == '/')
            lexer_lex_ignore_comment(self);
        else if (isspace(c))
            lexer_lex_ignore_space(self);
        else if (c == '\"')
            lexer_lex_double_qoutes(self);
        else
            lexer_lex_word(self);
    }
}

void
lexer_lex_ignore_space(lexer_t *self) {
    while (lexer_finished_p(self)) {
        char c = lexer_current_char(self);

        if (isspace(c))
            self->index++;
        else
            return;
    }
}

void
lexer_lex_ignore_comment(lexer_t *self) {
    self->index += 2;

    while (lexer_finished_p(self)) {
        char c = lexer_current_char(self);

        if (c == '\n') {
            self->index++;
            return;
        }
        else
            self->index++;
    }
}

void lexer_lex_double_qoutes_escape(lexer_t *self);

void
lexer_lex_double_qoutes(lexer_t *self) {
    self->index++;

    while (lexer_finished_p(self)) {
        char c = lexer_current_char(self);

        if (c == '\"') {
            size_t start = self->index;
            size_t end = self->index + strlen(self->string);
            char *string = string_dup(self->string);
            token_t *token = token_double_quotes_create(string, start, end);
            list_push(self->token_list, token);
            self->string[0] = '\0';
            self->string_length = 0;
            self->index++;
            return;
        } else if (c == '\\') {
            self->index++;
            lexer_lex_double_qoutes_escape(self);
        } else {
            lexer_collect_char(self, c);
            self->index++;
        }
    }
}

void
lexer_lex_double_qoutes_escape(lexer_t *self) {
    assert(!lexer_finished_p(self));

    char c = lexer_current_char(self);

    if (c == '\"') lexer_collect_char(self, '\"');
    else if (c == '\\') lexer_collect_char(self, '\\');
    else if (c == 'b') lexer_collect_char(self, '\b');
    else if (c == 'f') lexer_collect_char(self, '\f');
    else if (c == 'n') lexer_collect_char(self, '\n');
    else if (c == 'r') lexer_collect_char(self, '\r');
    else if (c == 't') lexer_collect_char(self, '\t');

    self->index++;
}

void
lexer_lex_word(lexer_t *self) {
    while (lexer_finished_p(self)) {
        char c = lexer_current_char(self);

        if (isspace(c)) {
            size_t start = self->index;
            size_t end = self->index + strlen(self->string);
            char *string = string_dup(self->string);
            token_t *token = token_word_create(string, start, end);
            list_push(self->token_list, token);
            self->string[0] = '\0';
            self->string_length = 0;
            return;
        } else {
            lexer_collect_char(self, c);
            self->index++;
        }
    }
}
