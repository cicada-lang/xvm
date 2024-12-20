#include "index.h"

xasm_t *
xasm_new(void) {
    xasm_t *self = new(xasm_t);
    self->xvm = xvm_new(1000);
    self->lexer = lexer_new();
    self->name_table = name_table_new();
    return self;
}

void
xasm_destroy(xasm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        xasm_t *self = *self_pointer;
        xvm_destroy(&self->xvm);
        lexer_destroy(&self->lexer);
        name_table_destroy(&self->name_table);
        free(self);
        *self_pointer = NULL;
    }
}
