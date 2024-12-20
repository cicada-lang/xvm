#include "index.h"

emulator_t *
emulator_new(size_t ram_size) {
    emulator_t *self = new(emulator_t);
    self->ram = ram_new(ram_size);
    self->value_stack = stack_new();
    self->return_stack = stack_new_with((destroy_fn_t *) frame_destroy);
    return self;
}

void
emulator_destroy(emulator_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        emulator_t *self = *self_pointer;
        stack_destroy(&self->value_stack);
        stack_destroy(&self->return_stack);
        ram_destroy(&self->ram);
        free(self);
        *self_pointer = NULL;
    }
}

void
emulator_step(emulator_t *self) {
    if (stack_is_empty(self->return_stack))
        return;

    frame_t *frame = stack_pop(self->return_stack);
    if (frame_is_end(frame))
        return;

    value_t value = frame_fetch_value(frame, self->ram);
    // proper tail-call = do not push finished frame.
    bool finished = frame_is_end(frame);
    if (!finished) stack_push(self->return_stack, frame);
    execute(self, frame, value);
    if (finished) frame_destroy(&frame);
}

void
emulator_run_until(emulator_t *self, size_t base_length) {
    while (stack_length(self->return_stack) > base_length) {
        emulator_step(self);
    }
}
