#pragma once

struct ram_t {
    size_t size;
    void *memory;
};

ram_t *ram_new(size_t size);
void ram_destroy(ram_t **self_pointer);

uint8_t ram_load_byte(const ram_t *self, size_t index);
