#pragma once

struct frame_t {
    value_t *program_cursor;
};

frame_t *frame_new(value_t *program_cursor);
