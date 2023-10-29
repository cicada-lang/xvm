#pragma once

frame_t *frame_create(program_t *program);
void frame_destroy(frame_t **self_p);
bool frame_is_end(frame_t *self);
byte_t frame_fetch_byte(frame_t *self);
instruction_t frame_fetch_instruction(frame_t *self);
value_t frame_fetch_value(frame_t *self);
word_t *frame_fetch_word(frame_t *self);
