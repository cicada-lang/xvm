#pragma once

struct assembler_t {
    lexer_t *lexer;
};

assembler_t *assembler_new(void);
