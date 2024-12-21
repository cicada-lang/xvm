#include "index.h"

lexeme_t *
lexeme_new(char *name) {
    lexeme_t *self = new(lexeme_t);
    self->name = name;
    self->lexicon = lexicon_new();
    return self;
}

void
lexeme_destroy(lexeme_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        lexeme_t *self = *self_pointer;
        free(self->name);
        lexicon_destroy(&self->lexicon);
        free(self);
        *self_pointer = NULL;
    }
}
