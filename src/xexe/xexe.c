#include "index.h"

xexe_t *
xexe_new(size_t size, uint8_t *bytes) {
    xexe_t *self = new(xexe_t);
    self->size = size;
    self->bytes = bytes;
    return self;
}
