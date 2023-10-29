#pragma once

word_t *word_create(const char* name);
void word_destroy(word_t **self_p);
const char *word_name(word_t *self);
program_t *word_program(word_t *self);
void word_program_set(word_t *self, program_t *program);
primitive_t *word_primitive(word_t *self);
void word_primitive_set(word_t *self, primitive_t *primitive);
