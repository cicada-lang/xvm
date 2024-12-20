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

void xasm_asm(xasm_t *self, const char *string);
void xasm_asm_token(xasm_t *self, const token_t *token);

void xasm_emit_byte(xasm_t *self, uint8_t byte);
void xasm_emit_value(xasm_t *self, value_t value);

xexe_t *xasm_dump(xasm_t *self);
