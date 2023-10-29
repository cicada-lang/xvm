#include "index.h"

struct _return_stack_t {
    size_t size;
    frame_t **frames;
    size_t cursor;
};

return_stack_t *
return_stack_create(size_t size) {
    return_stack_t *self = (return_stack_t *) calloc(1, sizeof(return_stack_t));
    self->size = size;
    self->frames = (frame_t **) calloc(size, sizeof(frame_t *));
    self->cursor = 0;
    return self;
}

void
return_stack_destroy(return_stack_t **self_p) {
    assert(self_p);
    if (*self_p) {
        return_stack_t *self = *self_p;
        while (!return_stack_is_empty(self)) {
            frame_t *frame = return_stack_pop(self);
            frame_destroy(&frame);
        }

        free(self->frames);
        free(self);
        *self_p = NULL;
    }
}

frame_t *
return_stack_pop(return_stack_t *self) {
    assert(self->cursor > 0);
    self->cursor--;
    frame_t *frame = self->frames[self->cursor];
    self->frames[self->cursor] = NULL;
    return frame;
}

void
return_stack_push(return_stack_t *self, frame_t *frame) {
    self->frames[self->cursor] = frame;
    self->cursor++;
}

bool
return_stack_is_empty(return_stack_t *self) {
    return self->cursor == 0;
}
