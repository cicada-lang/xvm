#include "index.h"

frame_t *
frame_new(value_t *program_cursor) {
    frame_t *self = new(frame_t);
    self->program_cursor = program_cursor;
    return self;
}
