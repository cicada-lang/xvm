#include "index.h"

lexeme_t *
lexeme_new(const char *string, size_t address) {
    lexeme_t *self = new(lexeme_t);
    self->string = string;
    self->address = address;
    self->lexicon = lexicon_new();
    return self;
}

void
lexeme_destroy(lexeme_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        lexeme_t *self = *self_pointer;
        lexicon_destroy(&self->lexicon);
        free(self);
        *self_pointer = NULL;
    }
}
