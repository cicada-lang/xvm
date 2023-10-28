#include "everything.h"

struct _dict_t {
    size_t size;
    word_t **words;
};

dict_t *
dict_new(size_t size) {
    dict_t *self = (dict_t *) calloc(1, sizeof(dict_t));
    assert(self);
    self->size = size;
    self->words = (word_t **) calloc(size, sizeof(word_t *));
    assert(self->words);
    return self;
}

void
dict_destroy(dict_t **self_p) {
    assert (self_p);
    if (*self_p) {
        dict_t *self = *self_p;
        dict_purge(self);
        free(self);
        *self_p = NULL;
    }
}

void
dict_purge(dict_t *self) {
    for (size_t index = 0; index < self->size; index++) {
        if (self->words[index]) {
            word_destroy(&self->words[index]);
         }
    }
}

size_t
dict_size(dict_t *self) {
    return self->size;
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
dict_word(dict_t *self, const char *name) {
    size_t hash = string_hash(name);
    word_t *found = self->words[hash];
    if (found) return found;

    word_t *word = word_new(name);
    self->words[hash] = word;
    return word;
}
