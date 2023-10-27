#include "everything.h"

typedef void (primitive_t)(env_t *env);

struct _word_t {
    char *name;
    program_t *program;
    primitive_t *primitive;
    word_t *next;
};

word_t *
word_new(void) {
    word_t *self = (word_t *) calloc(1, sizeof(word_t));
    assert(self);
    return self;
}

void
word_destroy(word_t **self_p) {
    assert (self_p);
    if (*self_p) {
        word_t *self = *self_p;
        free(self->name);
        program_destroy(&self->program);
        // self->primitive
        word_destroy(&self->next);
        free(self);
        *self_p = NULL;
    }
}
