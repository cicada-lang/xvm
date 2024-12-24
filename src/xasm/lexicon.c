#include "index.h"

lexicon_t *
lexicon_new(void) {
    lexicon_t *self = new(lexicon_t);
    self->lexeme_hash = hash_new_of_string_key();
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

// one lexeme one line -- <string> <address>
// <address> in explicit 0x format.

void
lexicon_print(lexicon_t *self, file_t *file) {
    // TODO only the first level for now.

    lexeme_t *lexeme = hash_first(self->lexeme_hash);
    while (lexeme) {
        fprintf(file, "%s 0x%lx\n", lexeme->string, lexeme->address);
        lexeme = hash_next(self->lexeme_hash);
    }
}
