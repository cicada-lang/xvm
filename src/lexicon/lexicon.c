#include "index.h"

lexicon_t *
lexicon_new(void) {
    lexicon_t *self = new(lexicon_t);
    self->lexeme_hash = hash_new();
    hash_set_destroy_fn(self->lexeme_hash, (destroy_fn_t *) lexeme_destroy);
    return self;
}

void
lexicon_destroy(lexicon_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        lexicon_t *self = *self_pointer;
        hash_destroy(&self->lexeme_hash);
        free(self);
        *self_pointer = NULL;
    }
}
