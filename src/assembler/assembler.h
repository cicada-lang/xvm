#pragma once

struct assembler_t {
    lexer_t *lexer;
};

assembler_t *assembler_new(void);
void assembler_destroy(assembler_t **self_pointer);
