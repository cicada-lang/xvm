#pragma once

typedef struct _xvm_t xvm_t;

xvm_t *xvm_create(void);
void xvm_destroy(xvm_t **self_p);
word_t *xvm_word(xvm_t *self, const char *name);
program_t *xvm_program(xvm_t *self, const char *name);
