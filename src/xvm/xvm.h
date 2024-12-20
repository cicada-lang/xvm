#pragma once

struct xvm_t {
    ram_t *ram;
    stack_t *value_stack;
    stack_t *return_stack;
};

xvm_t *xvm_new(size_t ram_size);
void xvm_destroy(xvm_t **self_pointer);

void xvm_step(xvm_t *self);
void xvm_run_until(xvm_t *self, size_t base_length);
