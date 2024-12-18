#include "index.h"

frame_t *
frame_new(value_t *program_counter) {
    frame_t *self = new(frame_t);
    self->program_counter = program_counter;
    return self;
}
