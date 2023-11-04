#include "index.h"

struct _program_t {
    size_t size;
    byte_t *bytes;
};

program_t *
program_create(void) {
    program_t *self = (program_t *) calloc(1, sizeof(program_t));
    self->size = 0;
    self->bytes = NULL;
    return self;
}

void
program_destroy(program_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        program_t *self = *self_ptr;
        free(self->bytes);
        free(self);
        *self_ptr = NULL;
    }
}

size_t
program_byte_size(program_t *self) {
    return self->size;
}

byte_t
program_fetch_byte(program_t *self, size_t index) {
    return *(self->bytes + index);
}

instruction_t
program_fetch_instruction(program_t *self, size_t index) {
    return (instruction_t) program_fetch_byte(self, index);
}

value_t
program_fetch_value(program_t *self, size_t index) {
    return *(value_t *)(self->bytes + index);
}

word_t *
program_fetch_word(program_t *self, size_t index) {
    return *(word_t **)(self->bytes + index);
}

void
program_append_value(program_t *self, value_t value) {
    size_t addend = sizeof(VALUE) + sizeof(value);
    byte_t *bytes = (byte_t *) calloc(self->size + addend, sizeof(byte_t));
    memcpy(bytes, self->bytes, self->size);
    free(self->bytes);
    self->bytes = bytes;

    *(instruction_t *)(self->bytes + self->size) = VALUE;
    self->size += sizeof(VALUE);

    *(value_t *)(self->bytes + self->size) = value;
    self->size += sizeof(value);
}

void
program_append_call(program_t *self, const word_t *word) {
    size_t addend = sizeof(CALL) + sizeof(word);
    byte_t *bytes = (byte_t *) calloc(self->size + addend, sizeof(byte_t));
    memcpy(bytes, self->bytes, self->size);
    free(self->bytes);
    self->bytes = bytes;

    *(instruction_t *)(self->bytes + self->size) = CALL;
    self->size += sizeof(CALL);

    *(const word_t **)(self->bytes + self->size) = word;
    self->size += sizeof(word);
}
