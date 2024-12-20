#include "index.h"

xexe_t *
xexe_new(size_t size, uint8_t *bytes) {
    xexe_t *self = new(xexe_t);
    self->size = size;
    self->bytes = bytes;
    return self;
}

void
xexe_destroy(xexe_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        xexe_t *self = *self_pointer;
        free(self->bytes);
        free(self);
        *self_pointer = NULL;
    }
}
