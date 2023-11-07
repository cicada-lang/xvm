#pragma once

lexer_t *lexer_create(const char *code);
void lexer_destroy(lexer_t **self_ptr);

list_t *lexer_token_list(lexer_t *self);
void lexer_lex(lexer_t *self);
