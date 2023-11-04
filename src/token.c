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
    token_t *self = allocate(sizeof(token_t));
    self->kind = TOKEN_WORD;
    self->string = string;
    self->start = start;
    self->end = end;
    return self;
}

token_t *
token_string_create(char *string, size_t start, size_t end) {
    token_t *self = allocate(sizeof(token_t));
    self->kind = TOKEN_STRING;
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

const char *
token_string(token_t *self) {
    return self->string;
}

void
token_destroy(token_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        token_free(*self_ptr);
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
