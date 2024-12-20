#pragma once

struct xexe_t {
    size_t size;
    uint8_t *bytes;
};

xexe_t *xexe_new(size_t size, uint8_t *bytes);
