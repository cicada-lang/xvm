#pragma once

struct vm_t {
    size_t ram_size;
    value_t *ram;
    stack_t *value_stack;
    stack_t *return_stack;
};
