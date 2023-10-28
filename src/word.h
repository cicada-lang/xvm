#pragma once

word_t *word_create(const char* name);
void word_destroy(word_t **self_p);
const char *word_name(word_t *self);
program_t *word_program(word_t *self);
