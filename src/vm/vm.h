#pragma once

struct vm_t {
    size_t ram_size;
    value_t *ram;
    stack_t *value_stack;
    stack_t *frame_stack;
};

vm_t *vm_new(size_t ram_size);
void vm_destroy(vm_t **self_pointer);
