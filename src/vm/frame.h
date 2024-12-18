#pragma once

struct frame_t {
    value_t *program_counter;
};

frame_t *frame_new(value_t *program_counter);
void frame_destroy(frame_t **self_pointer);
