#include "index.h"

ram_t *
ram_new(size_t size) {
    ram_t *self = new(ram_t);
    self->size = size;
    self->memory = allocate(size);
    return self;
}

void
ram_destroy(ram_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        ram_t *self = *self_pointer;
        free(self->memory);
        free(self);
        *self_pointer = NULL;
    }
}

uint8_t
ram_load_byte(const ram_t *self, size_t index) {
    assert(index < self->size);
    uint8_t *bytes =  self->memory;
    return bytes[index];
}
