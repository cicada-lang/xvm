#include "index.h"

xasm_t *
xasm_new(void) {
    xasm_t *self = new(xasm_t);
    size_t init_ram_size = 64 * 1024;
    self->xvm = xvm_new(init_ram_size);
    self->lexer = lexer_new();
    self->name_table = name_table_new();
    self->cursor = 0;
    self->ram_expand_step = init_ram_size;
    return self;
}

void
xasm_destroy(xasm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        xasm_t *self = *self_pointer;
        xvm_destroy(&self->xvm);
        lexer_destroy(&self->lexer);
        name_table_destroy(&self->name_table);
        free(self);
        *self_pointer = NULL;
    }
}

void
xasm_asm(xasm_t *self, const char *string) {
    self->lexer->string = string;
    lexer_lex(self->lexer);

    token_t *token = list_first(self->lexer->token_list);
    while (token) {
        xasm_asm_token(self, token);
        token = list_next(self->lexer->token_list);
    }

    list_destroy(&self->lexer->token_list);
}

void
xasm_asm_token(xasm_t *self, const token_t *token) {
    (void) self;
    (void) token;
}
