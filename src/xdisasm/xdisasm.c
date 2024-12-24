#include "index.h"

xdisasm_t *
xdisasm_new(size_t ram_size) {
    xdisasm_t *self = new(xdisasm_t);
    self->ram = ram_new(ram_size);
    return self;
}

void
xdisasm_destroy(xdisasm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        xdisasm_t *self = *self_pointer;
        ram_destroy(&self->ram);
        free(self);
        *self_pointer = NULL;
    }
}

void
xdisasm_disasm(const blob_t *blob, const blob_t *lexi_blob) {
    (void) blob;
    (void) lexi_blob;
    printf("[xdisasm_disasm] TODO\n");
}
