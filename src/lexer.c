#include "index.h"

struct _lexer_t {
    char *code;
};

lexer_t *lexer_create(char *code) {
    lexer_t *self = (lexer_t *) calloc(1, sizeof(lexer_t));
    self->code = code;
    return self;
}

void
lexer_destroy(lexer_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        lexer_t *self = *self_ptr;
        free(self->code);
        free(self);
        *self_ptr = NULL;
    }
}
