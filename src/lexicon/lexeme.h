#pragma once

struct lexeme_t {
    const char *string;
    size_t address;
    lexicon_t *lexicon;
};

lexeme_t *lexeme_new(const char *string, size_t address);
void lexeme_destroy(lexeme_t **self_pointer);
