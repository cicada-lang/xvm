#include "index.h"

xasm_t *
xasm_new(void) {
    xasm_t *self = new(xasm_t);
    self->lexer = lexer_new();
    self->xvm = xvm_new(1000);
    return self;
}

void
xasm_destroy(xasm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        xasm_t *self = *self_pointer;
        lexer_destroy(&self->lexer);
        free(self);
        *self_pointer = NULL;
    }
}
