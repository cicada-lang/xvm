#pragma once

struct xasm_t {
    lexer_t *lexer;
    xvm_t *xvm;
};

xasm_t *xasm_new(void);
void xasm_destroy(xasm_t **self_pointer);
