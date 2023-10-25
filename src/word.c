#include "everything.h"

typedef void (primitive_fn_t)(env_t *env);

struct _word_t {
    char *name;
    program_t *program;
    primitive_fn_t *primitive_fn;
    word_t *next;
};


void
word_destroy(word_t **self_p) {
    assert (self_p);
    if (*self_p) {
        word_t *self = *self_p;
        free(self->name);
        // self->program
        // self->primitive_fn
        word_destroy(&self->next);
        free(self);
        *self_p = NULL;
    }
}
