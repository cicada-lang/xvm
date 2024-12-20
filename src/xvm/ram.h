#pragma once

struct ram_t {
    size_t size;
    uint8_t *bytes;
};

ram_t *ram_new(size_t size);
void ram_destroy(ram_t **self_pointer);

uint8_t ram_load_byte(const ram_t *self, size_t address);
value_t ram_load_value(const ram_t *self, size_t address);
opcode_t ram_load_opcode(const ram_t *self, size_t address);

void ram_store_byte(const ram_t *self, size_t address, uint8_t byte);
