#include "index.h"

struct program_t {
    size_t size;
    byte_t *bytes;
};

program_t *
program_create(void) {
    program_t *self = allocate(sizeof(program_t));
    self->size = 0;
    self->bytes = NULL;
    return self;
}

void
program_destroy(program_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        program_t *self = *self_pointer;
        free(self->bytes);
        free(self);
        *self_pointer = NULL;
    }
}

size_t
program_byte_size(const program_t *self) {
    return self->size;
}

byte_t
program_fetch_byte(const program_t *self, size_t index) {
    return *(self->bytes + index);
}

opcode_t
program_fetch_opcode(const program_t *self, size_t index) {
    return (opcode_t) program_fetch_byte(self, index);
}

value_t
program_fetch_value(const program_t *self, size_t index) {
    return *(value_t *)(self->bytes + index);
}

word_t *
program_fetch_word(const program_t *self, size_t index) {
    return *(word_t **)(self->bytes + index);
}

void
program_append_call(program_t *self, const word_t *word) {
    size_t addend = sizeof(CALL) + sizeof(word);
    byte_t *bytes = allocate_array(self->size + addend, sizeof(byte_t));
    memcpy(bytes, self->bytes, self->size);
    free(self->bytes);
    self->bytes = bytes;

    *(opcode_t *)(self->bytes + self->size) = CALL;
    self->size += sizeof(CALL);

    *(const word_t **)(self->bytes + self->size) = word;
    self->size += sizeof(word);
}

void
program_append_literal_value(
    program_t *self,
    opcode_t opcode,
    value_t value
) {
    size_t addend = sizeof(opcode) + sizeof(value);
    byte_t *bytes = allocate_array(self->size + addend, sizeof(byte_t));
    memcpy(bytes, self->bytes, self->size);
    free(self->bytes);
    self->bytes = bytes;

    *(opcode_t *)(self->bytes + self->size) = opcode;
    self->size += sizeof(opcode);

    *(value_t *)(self->bytes + self->size) = value;
    self->size += sizeof(value);
}

void
program_append_literal_int(program_t *self, int64_t n) {
    program_append_literal_value(self, LITERAL_INT, (value_t) n);
}

void
program_append_literal_string(program_t *self, char *string) {
    program_append_literal_value(self, LITERAL_STRING, (value_t) string);
}

void
program_append_literal_word(program_t *self, word_t *word) {
    program_append_literal_value(self, LITERAL_WORD, (value_t) word);
}

void
program_append_literal_program(program_t *self, program_t *program) {
    program_append_literal_value(self, LITERAL_PROGRAM, (value_t) program);
}
