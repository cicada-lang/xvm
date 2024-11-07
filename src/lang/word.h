#pragma once

word_t *word_new(const char* name);
void word_destroy(word_t **self_pointer);

const char *word_name(word_t *self);

program_t *word_program(word_t *self);
void word_program_set(word_t *self, program_t *program);

program_t *word_type_program(word_t *self);
void word_type_program_set(word_t *self, program_t *program);

primitive_t *word_primitive(word_t *self);
void word_primitive_set(word_t *self, primitive_t *primitive);
