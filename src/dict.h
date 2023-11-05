#pragma once

dict_t *dict_create(size_t size);
void dict_destroy(dict_t **self_ptr);

void dict_purge(dict_t *self);
word_t *dict_word(dict_t *self, const char *name);
