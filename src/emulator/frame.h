#pragma once

struct frame_t {
    value_t *program_counter;
};

frame_t *frame_new(value_t *program_counter);
void frame_destroy(frame_t **self_pointer);

value_t frame_fetch_value(frame_t *self);
bool frame_is_end(const frame_t *self);
