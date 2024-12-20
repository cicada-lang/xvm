#include "index.h"

xasm_t *
xasm_new(void) {
    xasm_t *self = new(xasm_t);
    size_t init_ram_size = 64 * 1024;
    self->xvm = xvm_new(init_ram_size);
    self->lexer = lexer_new();
    self->name_table = name_table_new();
    self->cursor = 0;
    self->ram_expand_step = init_ram_size;
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
