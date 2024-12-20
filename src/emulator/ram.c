#include "index.h"

ram_t *
ram_new(size_t size) {
    ram_t *self = new(ram_t);
    self->size = size;
    self->bytes = allocate(size);
    return self;
}
