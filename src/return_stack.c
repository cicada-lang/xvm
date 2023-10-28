#include "index.h"

struct _return_stack_t {
    size_t size;
    return_frame_t **return_frames;
    size_t cursor;
};

return_stack_t *
return_stack_create(size_t size) {
    return_stack_t *self = (return_stack_t *) calloc(1, sizeof(return_stack_t));
    self->size = size;
    self->return_frames = (return_frame_t **) calloc(size, sizeof(return_frame_t *));
    self->cursor = 0;
    return self;
}

void
return_stack_destroy(return_stack_t **self_p) {
    assert(self_p);
    if (*self_p) {
        return_stack_t *self = *self_p;
        free(self->return_frames);
        while (!return_stack_is_empty(self)) {
            return_frame_t *return_frame = return_stack_pop(self);
            return_frame_destroy(&return_frame);
        }

        free(self);
        *self_p = NULL;
    }
}

return_frame_t *
return_stack_pop(return_stack_t *self) {
    assert(self->cursor > 0);
    self->cursor--;
    return_frame_t *return_frame = self->return_frames[self->cursor];
    self->return_frames[self->cursor] = NULL;
    return return_frame;
}

void
return_stack_push(return_stack_t *self, return_frame_t *return_frame) {
    self->return_frames[self->cursor] = return_frame;
    self->cursor++;
}

bool
return_stack_is_empty(return_stack_t *self) {
    return self->cursor == 0;
}
