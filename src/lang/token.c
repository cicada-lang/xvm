#include "index.h"

typedef enum {
    TOKEN_WORD,
    TOKEN_DOUBLE_QUOTES,
} token_kind_t;

struct _token_t {
    token_kind_t kind;
    char *string;
    size_t start;
    size_t end;
};

token_t *
token_word_create(char *string, size_t start, size_t end) {
    token_t *self = allocate(sizeof(token_t));
    self->kind = TOKEN_WORD;
    self->string = string;
    self->start = start;
    self->end = end;
    return self;
}

token_t *
token_double_quotes_create(char *string, size_t start, size_t end) {
    token_t *self = allocate(sizeof(token_t));
    self->kind = TOKEN_DOUBLE_QUOTES;
    self->string = string;
    self->start = start;
    self->end = end;
    return self;
}

void
token_free(token_t *self) {
    free(self->string);
    free(self);
}

void
token_destroy(token_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        token_free(*self_pointer);
        *self_pointer = NULL;
    }
}

const char *
token_string(token_t *self) {
    return self->string;
}

bool
token_word_p(token_t *self) {
    return self->kind == TOKEN_WORD;
}

bool
token_double_quotes_p(token_t *self) {
    return self->kind == TOKEN_DOUBLE_QUOTES;
}
