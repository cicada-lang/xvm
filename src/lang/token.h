#pragma once

token_t *token_word_new(char *string, size_t start, size_t end);
token_t *token_double_quotes_new(char *string, size_t start, size_t end);
void token_free(token_t *self);
void token_destroy(token_t **self_pointer);

const char *token_string(token_t *self);
bool token_is_word(token_t *self);
bool token_is_double_quotes(token_t *self);
