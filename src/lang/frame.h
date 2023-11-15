#pragma once

frame_t *frame_create(const program_t *program);
void frame_destroy(frame_t **self_pointer);

bool frame_end_p(frame_t *self);

byte_t frame_fetch_byte(frame_t *self);
opcode_t frame_fetch_opcode(frame_t *self);
value_t frame_fetch_value(frame_t *self);
word_t *frame_fetch_word(frame_t *self);
