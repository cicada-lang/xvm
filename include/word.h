#pragma once

typedef struct _word_t word_t;

word_t *word_new(void);
void word_destroy(word_t **self_p);
