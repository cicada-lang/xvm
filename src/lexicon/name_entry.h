#pragma once

struct name_entry_t {
    char *name;
    lexicon_t *lexicon;
};

name_entry_t *name_entry_new(char *name);
void name_entry_destroy(name_entry_t **self_pointer);
