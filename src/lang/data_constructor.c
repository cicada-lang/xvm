#include "index.h"

struct _data_constructor_t {
    const datatype_t *datatype;
    const word_t *name;
    size_t arity;
};

data_constructor_t *
data_constructor_create(const datatype_t *datatype, const word_t *name, size_t arity) {
    data_constructor_t *self = allocate(sizeof(data_constructor_t));
    self->datatype = datatype;
    self->name = name;
    self->arity = arity;
    return self;
}

void
data_constructor_destroy(data_constructor_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        data_constructor_t *self = *self_pointer;
        free(self);
        *self_pointer = NULL;
    }
}
