#include "index.h"

typedef enum {
    TOKEN_WORD,
    TOKEN_STRING,
} token_kind_t;

struct _token_t {
    token_kind_t kind;
    char *string;
    size_t start;
    size_t end;
};

token_t *
token_word_create(char *string, size_t start, size_t end) {
    token_t *self = (token_t *) calloc(1, sizeof(token_t));
    self->kind = TOKEN_WORD;
    self->string = string;
    self->start = start;
    self->end = end;
    return self;
}

token_t *
token_string_create(char *string, size_t start, size_t end) {
    token_t *self = (token_t *) calloc(1, sizeof(token_t));
    self->kind = TOKEN_STRING;
    self->string = string;
    self->start = start;
    self->end = end;
    return self;
}

void
token_destroy(token_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        token_t *self = *self_ptr;
        free(self->string);
        free(self);
        *self_ptr = NULL;
    }
}

bool
token_word_p(token_t *self) {
    return self->kind == TOKEN_WORD;
}

bool
token_string_p(token_t *self) {
    return self->kind == TOKEN_STRING;
}