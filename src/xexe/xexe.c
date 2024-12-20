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

xexe_t *
xexe_read(file_t *file) {
    size_t size = file_size(file);
    uint8_t *bytes = file_read_bytes(file);
    return xexe_new(size, bytes);
}

void
xexe_write(xexe_t *self, file_t *file) {
    file_write_bytes(file, self->bytes, self->size);
}
