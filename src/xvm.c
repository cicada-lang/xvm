#include "everything.h"

#define DICT_SIZE 1000003

xvm_t *
xvm_new(void) {
    xvm_t *self = (xvm_t *) calloc(1, sizeof(xvm_t));
    self->dict = dict_new(DICT_SIZE);
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

void
xvm_define(xvm_t *self, const char *name, const char **body) {
    word_t *word = dict_word(self->dict, name);
    printf("define: %s\n", word_name(word));

    while (*body) {
        word_t *word = dict_word(self->dict, *body);
        printf("next: %s\n", word_name(word));
        body++;
    }
}
