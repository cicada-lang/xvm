#include "index.h"

struct _program_t {
    size_t size;
    byte_t *bytes;
};

program_t *
program_create() {
    program_t *self = (program_t *) calloc(1, sizeof(program_t));
    self->size = 0;
    self->bytes = NULL;
    return self;
}

void
program_destroy(program_t **self_p) {
    assert(self_p);
    if (*self_p) {
        program_t *self = *self_p;
        free(self->bytes);
        free(self);
        *self_p = NULL;
    }
}

size_t
program_byte_size(program_t *self) {
    return self->size;
}

byte_t
program_fetch_byte(program_t *self, size_t index) {
    return self->bytes[index];
}

instruction_t
program_fetch_instruction(program_t *self, size_t index) {
    return (instruction_t) program_fetch_byte(self, index);
}
