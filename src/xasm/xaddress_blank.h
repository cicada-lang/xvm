#pragma once

struct xaddress_blank_t {
    char *string;
    size_t blank_address;
};

xaddress_blank_t *xaddress_blank_new(char *string, size_t blank_address);
