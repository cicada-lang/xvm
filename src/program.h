#pragma once

// A program is a dynamic byte array with dynamic length.

program_t *program_create(void);
void program_destroy(program_t **self_ptr);
size_t program_byte_size(program_t *self);
byte_t program_fetch_byte(program_t *self, size_t index);
instruction_t program_fetch_instruction(program_t *self, size_t index);
value_t program_fetch_value(program_t *self, size_t index);
word_t *program_fetch_word(program_t *self, size_t index);
void program_append_value(program_t *self, value_t value);
void program_append_call(program_t *self, const word_t *word);
// void program_append_program(program_t *self, const program_t *program);
