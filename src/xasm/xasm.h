#pragma once

struct xasm_t {
    xvm_t *xvm;
    lexer_t *lexer;
    name_table_t *name_table;
    size_t cursor;
    size_t ram_expand_step;
};

xasm_t *xasm_new(void);
void xasm_destroy(xasm_t **self_pointer);
