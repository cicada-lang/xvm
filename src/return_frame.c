#include "index.h"

struct _return_frame_t {
    size_t index;
    const program_t *program;
};

return_frame_t *
return_frame_create(const program_t *program) {
    return_frame_t *self = (return_frame_t *) calloc(1, sizeof(return_frame_t));
    self->index = 0;
    self->program = program;
    return self;
}

void
return_frame_destroy(return_frame_t **self_p) {
    assert(self_p);
    if (*self_p) {
        return_frame_t *self = *self_p;
        free(self);
        *self_p = NULL;
    }
}
