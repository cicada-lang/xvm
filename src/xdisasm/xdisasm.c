#include "index.h"

xdisasm_t *
xdisasm_new(size_t ram_size) {
    xdisasm_t *self = new(xdisasm_t);
    self->ram = ram_new(ram_size);
    return self;
}
