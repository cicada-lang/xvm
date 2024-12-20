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

uint8_t
ram_load_byte(const ram_t *self, size_t address) {
    assert(address < self->size);
    return *((uint8_t *) self->bytes + address);
}

value_t
ram_load_value(const ram_t *self, size_t address) {
    assert(address + 8 < self->size);
    return *((value_t *) (self->bytes + address));
}

opcode_t
ram_load_opcode(const ram_t *self, size_t address) {
    return ram_load_byte(self, address);
}

void
ram_store_byte(const ram_t *self, size_t address, uint8_t byte) {
    assert(address < self->size);
    *((uint8_t *) self->bytes + address) = byte;
}

void
ram_store_value(const ram_t *self, size_t address, value_t value) {
    assert(address + 8 < self->size);
    *((value_t *) (self->bytes + address)) = value;
}

void
ram_store_opcode(const ram_t *self, size_t address, opcode_t opcode) {
    ram_store_byte(self, address, opcode);
}
