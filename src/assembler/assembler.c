#include "index.h"

assembler_t *
assembler_new(void) {
    assembler_t *self = new(assembler_t);
    self->lexer = lexer_new();
    self->xvm = xvm_new(1000);
    return self;
}

void
assembler_destroy(assembler_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        assembler_t *self = *self_pointer;
        lexer_destroy(&self->lexer);
        free(self);
        *self_pointer = NULL;
    }
}
