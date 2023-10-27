#include "everything.h"

struct _program_t {
    size_t size;
    value_t *values;
};

program_t *program_new(size_t size) {
    program_t *self = (program_t *) calloc(1, sizeof(program_t));
    assert(self);
    self->size = size;
    self->values = (value_t *) calloc(size, sizeof(value_t));
    assert(self->values);
    return self;
}

void program_destroy(program_t **self_p) {
    assert (self_p);
    if (*self_p) {
        program_t *self = *self_p;
        free(self->values);
        free(self);
        *self_p = NULL;
    }
}
