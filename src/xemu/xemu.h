#pragma once

struct xemu_t {
    ram_t *ram;
    stack_t *value_stack;
    stack_t *return_stack;
};

xemu_t *xemu_new(size_t ram_size);
void xemu_destroy(xemu_t **self_pointer);

void xemu_step(xemu_t *self);
void xemu_run_until(xemu_t *self, size_t base_length);
void xemu_run(xemu_t *self);

void xemu_emu(const blob_t *blob);
