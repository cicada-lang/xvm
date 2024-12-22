#include "index.h"

struct xasm_t {
    ram_t *ram;
    lexer_t *lexer;
    lexicon_t *lexicon;
    size_t cursor;
    size_t ram_expand_step;
    stack_t *xaddress_blank_stack;
};

xasm_t *
xasm_new(void) {
    xasm_t *self = new(xasm_t);
    size_t init_ram_size = 64 * 1024;
    self->ram = ram_new(init_ram_size);
    self->lexer = lexer_new();
    self->lexer->line_comment_start = "//";
    self->lexicon = lexicon_new();
    self->cursor = 0;
    self->ram_expand_step = init_ram_size;
    self->xaddress_blank_stack = stack_new_with(
        (destroy_fn_t *) xaddress_blank_destroy);
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
        stack_destroy(&self->xaddress_blank_stack);
        free(self);
        *self_pointer = NULL;
    }
}

void
xasm_run(xasm_t *self, const char *string) {
    self->lexer->string = string;
    lexer_lex(self->lexer);

    token_t *token = list_first(self->lexer->token_list);
    while (token) {
        xasm_step(self, token);
        token = list_next(self->lexer->token_list);
    }

    list_destroy(&self->lexer->token_list);
}

static bool
xasm_step_opcode(xasm_t *self, const token_t *token) {
    for (size_t i = 0; i < 256; i++) {
        opcode_t opcode = (opcode_t) i;
        const char *mnemonic = opcode_table[opcode];
        if (!mnemonic) continue;

        if (string_equal(token->string, mnemonic)) {
            xasm_emit_byte(self, opcode);
            return true;
        }
    }

    return false;
}

static bool
xasm_step_constant(xasm_t *self, const token_t *token) {
    if (string_equal(token->string, "null")) {
        xasm_emit_byte(self, OP_LIT);
        xasm_emit_value(self, xnull());
        return true;
    }

    if (string_equal(token->string, "false")) {
        xasm_emit_byte(self, OP_LIT);
        xasm_emit_value(self, xfalse());
        return true;
    }

    if (string_equal(token->string, "true")) {
        xasm_emit_byte(self, OP_LIT);
        xasm_emit_value(self, xtrue());
        return true;
    }

    return false;
}

static bool
xasm_step_xint(xasm_t *self, const token_t *token) {
    if (string_is_xint(token->string)) {
        xasm_emit_byte(self, OP_LIT);
        xasm_emit_value(self, xint(string_parse_xint(token->string)));
        return true;
    }

    return false;
}

static bool
xasm_step_xfloat(xasm_t *self, const token_t *token) {
    if (string_is_double(token->string)) {
        xasm_emit_byte(self, OP_LIT);
        xasm_emit_value(self, xfloat(string_parse_double(token->string)));
        return true;
    }

    return false;
}

static bool
xasm_step_label(xasm_t *self, const token_t *token) {
    if (!string_starts_with(token->string, "@"))
        return false;

    size_t length = string_length(token->string);
    char *key = string_slice(token->string, 1, length);
    lexeme_t *lexeme = lexeme_new(key, self->cursor);
    bool ok = hash_set(self->lexicon->lexeme_hash, key, lexeme);
    if (ok) return true;

    fprintf(
        stderr,
        "[xasm_step_label] label already used: %s\n",
        token->string);
    exit(1);
}

void
xasm_step(xasm_t *self, const token_t *token) {
    if (xasm_step_opcode(self, token)) return;
    if (xasm_step_constant(self, token)) return;
    if (xasm_step_xint(self, token)) return;
    if (xasm_step_xfloat(self, token)) return;
    if (xasm_step_label(self, token)) return;

    fprintf(
        stderr,
        "[xasm_step] unknown token: %s\n",
        token->string);
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

blob_t *
xasm_dump(xasm_t *self) {
    blob_t *blob = blob_new(self->cursor);
    blob_copy_from(blob, self->ram->bytes);
    return blob;
}

blob_t *
xasm_asm(const char *string) {
    xasm_t *self = xasm_new();
    xasm_run(self, string);
    blob_t *blob = xasm_dump(self);
    xasm_destroy(&self);
    return blob;
}
