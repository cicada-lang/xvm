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
