#include "index.h"

struct dict_t {
    size_t size;
    word_t **words;
};

dict_t *
dict_new(size_t size) {
    dict_t *self = allocate(sizeof(dict_t));
    self->size = size;
    self->words = allocate_array(size, sizeof(word_t *));
    return self;
}

void
dict_destroy(dict_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        dict_t *self = *self_pointer;
        dict_purge(self);
        free(self);
        *self_pointer = NULL;
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

    word_t *word = word_new(name);
    self->words[hash] = word;
    return word;
}
