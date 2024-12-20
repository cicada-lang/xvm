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

void
ram_expand(ram_t *self, size_t size) {
    assert(size > self->size);
    self->size = size;
    self->bytes = realloc(self->bytes, size);
}

uint8_t
ram_get_byte(ram_t *self, size_t address) {
    assert(address < self->size);
    return *((uint8_t *) self->bytes + address);
}

value_t
ram_get_value(ram_t *self, size_t address) {
    assert(address + 8 < self->size);
    return *((value_t *) (self->bytes + address));
}

void
ram_set_byte(ram_t *self, size_t address, uint8_t byte) {
    assert(address < self->size);
    *((uint8_t *) self->bytes + address) = byte;
}

void
ram_set_value(ram_t *self, size_t address, value_t value) {
    assert(address + 8 < self->size);
    *((value_t *) (self->bytes + address)) = value;
}
