#pragma once

struct xexe_t {
    size_t size;
    uint8_t *bytes;
};

xexe_t *xexe_new(size_t size, uint8_t *bytes);
void xexe_destroy(xexe_t **self_pointer);

xexe_t *xexe_read(file_t *file);
void xexe_write(xexe_t *self, file_t *file);
