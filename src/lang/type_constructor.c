#include "index.h"

struct _type_constructor_t {
    size_t arity;
};

type_constructor_t *
type_constructor_create(size_t arity) {
    type_constructor_t *self = allocate(sizeof(type_constructor_t));
    self->arity = arity;
    return self;
}

void
type_constructor_destroy(type_constructor_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        type_constructor_t *self = *self_pointer;
        free(self);
        *self_pointer = NULL;
    }
}

size_t
type_constructor_arity(type_constructor_t *self) {
    return self->arity;
}
