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

size_t
string_hash(const char *s) {
    size_t max_index = 64 - 8;
    size_t index = 0;
    size_t hash = 0;
    while (*s) {
        hash += (*s) << (index % max_index);
        index++;
        s++;
    }

    return hash;
}

word_t *
xvm_word(xvm_t *self, const char *name) {
    size_t hash = string_hash(name);
    word_t *found = self->dict->words[hash];
    if (found) return found;

    word_t *word = word_create(name);
    self->dict->words[hash] = word;
    return word;
}
