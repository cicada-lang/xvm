#include "index.h"

xvm_t *
xvm_new(size_t ram_size) {
    xvm_t *self = new(xvm_t);
    self->ram = ram_new(ram_size);
    self->value_stack = stack_new();
    self->return_stack = stack_new_with((destroy_fn_t *) frame_destroy);
    return self;
}

void
xvm_destroy(xvm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        xvm_t *self = *self_pointer;
        stack_destroy(&self->value_stack);
        stack_destroy(&self->return_stack);
        ram_destroy(&self->ram);
        free(self);
        *self_pointer = NULL;
    }
}

void
xvm_step(xvm_t *self) {
    if (stack_is_empty(self->return_stack))
        return;

    frame_t *frame = stack_pop(self->return_stack);
    if (frame_is_end(frame, self->ram))
        return;

    opcode_t opcode = frame_fetch_opcode(frame, self->ram);

    // proper tail-call = do not push ended frame.

    bool is_end = frame_is_end(frame, self->ram);
    if (!is_end)
        stack_push(self->return_stack, frame);

    execute(self, frame, opcode);

    if (is_end)
        frame_destroy(&frame);
}

void
xvm_run_until(xvm_t *self, size_t base_length) {
    while (stack_length(self->return_stack) > base_length) {
        xvm_step(self);
    }
}
