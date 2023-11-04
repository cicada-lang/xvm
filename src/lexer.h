#pragma once

lexer_t *lexer_create(char *code);
void lexer_destroy(lexer_t **self_ptr);
token_t **lexer_tokens(lexer_t *self);
token_t **lexer_lex(lexer_t *self);
