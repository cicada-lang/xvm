#pragma once

typedef struct _word_t word_t;

word_t *word_new(const char* name);
void word_destroy(word_t **self_p);
const char *word_name(word_t *self);
