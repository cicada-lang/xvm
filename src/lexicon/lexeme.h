#pragma once

struct lexeme_t {
    char *string;
    lexicon_t *lexicon;
};

lexeme_t *lexeme_new(char *string);
void lexeme_destroy(lexeme_t **self_pointer);
