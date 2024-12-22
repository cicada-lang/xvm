#include "index.h"

xaddress_blank_t *
xaddress_blank_new(char *key, size_t blank_address) {
    xaddress_blank_t *self = new(xaddress_blank_t);
    self->key = key;
    self->blank_address = blank_address;
    return self;
}

void
xaddress_blank_destroy(xaddress_blank_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        xaddress_blank_t *self = *self_pointer;
        free(self->key);
        free(self);
        *self_pointer = NULL;
    }
}
