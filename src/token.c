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
