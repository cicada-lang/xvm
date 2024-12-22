#pragma once

struct xaddress_blank_t {
    char *key;
    size_t address;
};

xaddress_blank_t *xaddress_blank_new(char *key, size_t address);
void xaddress_blank_destroy(xaddress_blank_t **self_pointer);
