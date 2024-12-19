#include "index.h"

vm_t *
vm_new(size_t ram_size) {
    vm_t *self = new(vm_t);
    self->ram_size = ram_size;
    self->ram = allocate(ram_size * sizeof(value_t));
    self->value_stack = stack_new();
    self->return_stack = stack_new_with((destroy_fn_t *) frame_destroy);
    return self;
}

void
vm_destroy(vm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        vm_t *self = *self_pointer;
        stack_destroy(&self->value_stack);
        stack_destroy(&self->return_stack);
        free(self->ram);
        free(self);
        *self_pointer = NULL;
    }
}

void
vm_step(vm_t *self) {
    if (stack_is_empty(self->return_stack))
        return;

    frame_t *frame = stack_pop(self->return_stack);
    if (frame_is_end(frame))
        return;

    value_t value = frame_fetch_value(frame);
    // proper tail-call = do not push finished frame.
    bool finished = frame_is_end(frame);
    if (!finished) stack_push(self->return_stack, frame);
    execute(self, frame, value);
    if (finished) frame_destroy(&frame);
}

void
vm_run_until(vm_t *self, size_t base_length) {
    while (stack_length(self->return_stack) > base_length) {
        vm_step(self);
    }
}
