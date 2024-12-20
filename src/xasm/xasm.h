#pragma once

struct xasm_t {
    xvm_t *xvm;
    lexer_t *lexer;
    name_table_t *name_table;
};

xasm_t *xasm_new(void);
void xasm_destroy(xasm_t **self_pointer);
