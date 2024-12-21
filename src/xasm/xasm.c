#include "index.h"

xasm_t *
xasm_new(void) {
    xasm_t *self = new(xasm_t);
    size_t init_ram_size = 64 * 1024;
    self->ram = ram_new(init_ram_size);
    self->lexer = lexer_new();
    self->lexicon = lexicon_new();
    self->cursor = 0;
    self->ram_expand_step = init_ram_size;
    return self;
}

void
xasm_destroy(xasm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        xasm_t *self = *self_pointer;
        ram_destroy(&self->ram);
        lexer_destroy(&self->lexer);
        lexicon_destroy(&self->lexicon);
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
    if (string_equal(token->string, "NOP")) {
        xasm_emit_byte(self, OP_NOP);
        return;
    }

    if (string_equal(token->string, "null")) {
        xasm_emit_byte(self, OP_LIT);
        xasm_emit_value(self, xnull());
        return;
    }

    if (string_equal(token->string, "false")) {
        xasm_emit_byte(self, OP_LIT);
        xasm_emit_value(self, xfalse());
        return;
    }

    if (string_equal(token->string, "true")) {
        xasm_emit_byte(self, OP_LIT);
        xasm_emit_value(self, xtrue());
        return;
    }

    if (string_equal(token->string, "CALL")) {
        xasm_emit_byte(self, OP_CALL);
        return;
    }

    if (string_equal(token->string, "END")) {
        xasm_emit_byte(self, OP_END);
        return;
    }
}

static void
xasm_maybe_expend(xasm_t *self, size_t required_size) {
    if (self->cursor + required_size < self->ram->size)
        return;

    ram_expand(self->ram, self->ram->size + self->ram_expand_step);
}

void
xasm_emit_byte(xasm_t *self, uint8_t byte) {
    xasm_maybe_expend(self, sizeof(uint8_t));

    ram_set_byte(self->ram, self->cursor, byte);
    self->cursor += sizeof(uint8_t);
}

void
xasm_emit_value(xasm_t *self, value_t value) {
    xasm_maybe_expend(self, sizeof(value_t));

    ram_set_value(self->ram, self->cursor, value);
    self->cursor += sizeof(value_t);
}

xexe_t *
xasm_dump(xasm_t *self) {
    size_t size = self->cursor;
    uint8_t *bytes = allocate(size);
    memcpy(bytes, self->ram->bytes, size);
    return xexe_new(size, bytes);
}
