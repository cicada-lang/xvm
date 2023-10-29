#include "index.h"

struct _frame_t {
    size_t index;
    program_t *program;
};

frame_t *
frame_create(program_t *program) {
    frame_t *self = (frame_t *) calloc(1, sizeof(frame_t));
    self->index = 0;
    self->program = program;
    return self;
}

void
frame_destroy(frame_t **self_p) {
    assert(self_p);
    if (*self_p) {
        frame_t *self = *self_p;
        free(self);
        *self_p = NULL;
    }
}

bool
frame_is_end(frame_t *self) {
    return self->index >= program_byte_size(self->program);
}

byte_t
frame_fetch_byte(frame_t *self) {
    byte_t byte = program_fetch_byte(self->program, self->index);
    self->index += sizeof(byte_t);
    return byte;
}

instruction_t
frame_fetch_instruction(frame_t *self) {
    return (instruction_t) frame_fetch_byte(self);
}

value_t
frame_fetch_value(frame_t *self) {
    value_t value = program_fetch_value(self->program, self->index);
    self->index += sizeof(value_t);
    return value;
}

word_t *
frame_fetch_word(frame_t *self) {
    word_t *word = program_fetch_word(self->program, self->index);
    self->index += sizeof(word_t *);
    return word;
}
