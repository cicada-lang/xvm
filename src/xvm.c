#include "index.h"

struct _xvm_t {
    dict_t *dict;
};

#define DICT_SIZE 1000003

xvm_t *
xvm_create(void) {
    xvm_t *self = (xvm_t *) calloc(1, sizeof(xvm_t));
    self->dict = dict_create(DICT_SIZE);
    return self;
}

void
xvm_destroy(xvm_t **self_p) {
    assert (self_p);
    if (*self_p) {
        xvm_t *self = *self_p;
        dict_destroy(&self->dict);
        free(self);
        *self_p = NULL;
    }
}

word_t *
xvm_word(xvm_t *self, const char *name) {
    return dict_word(self->dict, name);
}

program_t *
xvm_program(xvm_t *self, const char *name) {
    word_t *word = xvm_word(self, name);
    return word_program(word);
}
