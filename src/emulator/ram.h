#pragma once

struct ram_t {
    size_t size;
    void *bytes;
};

ram_t *ram_new(size_t size);
void ram_destroy(ram_t **self_pointer);
