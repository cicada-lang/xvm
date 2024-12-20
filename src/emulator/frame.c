#include "index.h"

frame_t *
frame_new(value_t *program_counter) {
    frame_t *self = new(frame_t);
    self->program_counter = program_counter;
    return self;
}

void
frame_destroy(frame_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        frame_t *self = *self_pointer;
        free(self);
        *self_pointer = NULL;
    }
}

value_t
frame_fetch_value(frame_t *self) {
    value_t value = *self->program_counter;
    self->program_counter++;
    return value;
}

bool
frame_is_end(const frame_t *self) {
    (void) self;
    return false;
}
