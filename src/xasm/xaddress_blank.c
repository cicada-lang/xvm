#include "index.h"

xaddress_blank_t *
xaddress_blank_new(char *string, size_t blank_address) {
    xaddress_blank_t *self = new(xaddress_blank_t);
    self->string = string;
    self->blank_address = blank_address;
    return self;
}
