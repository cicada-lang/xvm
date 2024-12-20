#include "index.h"

assembler_t *
assembler_new(void) {
    assembler_t *self = new(assembler_t);
    self->lexer = lexer_new();
    return self;
}
