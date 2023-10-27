#include "everything.h"

struct _word_t {
    char *name;
    program_t *program;
    primitive_t *primitive;
    word_t *next;
};

word_t *
word_new(char *name) {
    word_t *self = (word_t *) calloc(1, sizeof(word_t));
    assert(self);
    self->name = name;
    return self;
}

void
word_destroy(word_t **self_p) {
    assert (self_p);
    if (*self_p) {
        word_t *self = *self_p;
        free(self->name);
        program_destroy(&self->program);
        word_destroy(&self->next);
        free(self);
        *self_p = NULL;
    }
}
