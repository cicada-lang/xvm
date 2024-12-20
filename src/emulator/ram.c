#include "index.h"

ram_t *
ram_new(size_t size) {
    ram_t *self = new(ram_t);
    self->size = size;
    self->bytes = allocate(size);
    return self;
}

void
ram_destroy(ram_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        ram_t *self = *self_pointer;
        free(self->bytes);
        free(self);
        *self_pointer = NULL;
    }
}
