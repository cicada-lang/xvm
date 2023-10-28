#include "index.h"

struct _program_t {
    size_t size;
    byte_t *bytes;
};

program_t *
program_new(size_t size) {
    program_t *self = (program_t *) calloc(1, sizeof(program_t));
    assert(self);
    self->size = size;
    self->bytes = (byte_t *) calloc(size, sizeof(byte_t));
    assert(self->bytes);
    return self;
}

void
program_destroy(program_t **self_p) {
    assert (self_p);
    if (*self_p) {
        program_t *self = *self_p;
        free(self->bytes);
        free(self);
        *self_p = NULL;
    }
}
