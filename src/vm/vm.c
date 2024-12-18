#include "index.h"

vm_t *
vm_new(size_t ram_size) {
    vm_t *self = new(vm_t);
    self->ram_size = ram_size;
    self->ram = allocate(ram_size * sizeof(value_t));
    self->value_stack = stack_new();
    self->frame_stack = stack_new();
    return self;
}

void
vm_destroy(vm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        vm_t *self = *self_pointer;
        stack_destroy(&self->value_stack);
        stack_destroy(&self->frame_stack);
        free(self->ram);
        free(self);
        *self_pointer = NULL;
    }
}
