#pragma once

xasm_t *xasm_new(void);
void xasm_destroy(xasm_t **self_pointer);

void xasm_run(xasm_t *self, const char *string);
void xasm_step(xasm_t *self, const token_t *token);

blob_t *xasm_dump(xasm_t *self);
blob_t *xasm_asm(const char *string);
