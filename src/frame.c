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
