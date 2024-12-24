#include "index.h"

frame_t *
frame_new(size_t address) {
    frame_t *self = new(frame_t);
    self->address = address;
    return self;
}

void
frame_destroy(frame_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        frame_t *self = *self_pointer;
        free(self);
        *self_pointer = NULL;
    }
}

value_t
frame_fetch_value(frame_t *self, ram_t *ram) {
    value_t value = ram_get_value(ram, self->address);
    self->address += sizeof(value_t);
    return value;
}

uint8_t
frame_fetch_byte(frame_t *self, ram_t *ram) {
    uint8_t byte = ram_get_byte(ram, self->address);
    self->address += sizeof(uint8_t);
    return byte;
}

opcode_t frame_fetch_opcode(frame_t *self, ram_t *ram) {
    opcode_t opcode = ram_get_byte(ram, self->address);
    self->address += sizeof(opcode_t);
    return opcode;
}

bool
frame_is_at_tail(const frame_t *self, ram_t *ram) {
    opcode_t opcode = ram_get_byte(ram, self->address);
    return opcode == OP_RET;
}
