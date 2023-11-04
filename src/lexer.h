#pragma once

lexer_t *lexer_create(char *code);
void lexer_destroy(lexer_t **self_ptr);
