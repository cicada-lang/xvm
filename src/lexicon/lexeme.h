#pragma once

struct lexeme_t {
    char *name;
    lexicon_t *lexicon;
};

lexeme_t *lexeme_new(char *name);
void lexeme_destroy(lexeme_t **self_pointer);
