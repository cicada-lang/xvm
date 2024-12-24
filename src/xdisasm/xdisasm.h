#pragma once

// note that this class is like xemu_t
// (not like xasm_t).

struct xdisasm_t {
    ram_t *ram;
};

xdisasm_t *xdisasm_new(size_t ram_size);
void xdisasm_destroy(xdisasm_t **self_pointer);

void xdisasm_disasm(const blob_t *blob);
