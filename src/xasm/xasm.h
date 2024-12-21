#pragma once

struct xasm_t {
    ram_t *ram;
    lexer_t *lexer;
    lexicon_t *lexicon;
    size_t cursor;
    size_t ram_expand_step;
};

xasm_t *xasm_new(void);
void xasm_destroy(xasm_t **self_pointer);

void xasm_run(xasm_t *self, const char *string);
void xasm_step(xasm_t *self, const token_t *token);

void xasm_emit_byte(xasm_t *self, uint8_t byte);
void xasm_emit_value(xasm_t *self, value_t value);

blob_t *xasm_dump(xasm_t *self);

blob_t *xasm_asm(const char *string);
