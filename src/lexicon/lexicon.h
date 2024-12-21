#pragma once

struct lexicon_t {
    hash_t *lexeme_hash;
};

lexicon_t *lexicon_new(void);
void lexicon_destroy(lexicon_t **self_pointer);
