#include "index.h"

lexeme_t *
lexeme_new(char *string) {
    lexeme_t *self = new(lexeme_t);
    self->string = string;
    self->lexicon = lexicon_new();
    return self;
}

void
lexeme_destroy(lexeme_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        lexeme_t *self = *self_pointer;
        free(self->string);
        lexicon_destroy(&self->lexicon);
        free(self);
        *self_pointer = NULL;
    }
}
