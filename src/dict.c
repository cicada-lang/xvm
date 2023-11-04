#include "index.h"

struct _dict_t {
    size_t size;
    word_t **words;
};

dict_t *
dict_create(size_t size) {
    dict_t *self = (dict_t *) calloc(1, sizeof(dict_t));
    self->size = size;
    self->words = (word_t **) calloc(size, sizeof(word_t *));
    return self;
}

void
dict_destroy(dict_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        dict_t *self = *self_ptr;
        dict_purge(self);
        free(self);
        *self_ptr = NULL;
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

word_t *
dict_word(dict_t *self, const char *name) {
    size_t hash = string_hash(name, self->size);
    word_t *found = self->words[hash];
    if (found) return found;

    word_t *word = word_create(name);
    self->words[hash] = word;
    return word;
}
