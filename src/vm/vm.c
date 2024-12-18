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
