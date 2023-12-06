#include "index.h"

struct _datatype_t {
    const word_t *name;
    list_t *data_constructor_list;
    bool is_closed;
};

datatype_t *
datatype_create(const word_t *name) {
    datatype_t *self = allocate(sizeof(datatype_t));
    self->name = name;
    self->data_constructor_list = list_create();
    self->is_closed = false;
    return self;
}

void
datatype_destroy(datatype_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        datatype_t *self = *self_pointer;
        list_destroy(&self->data_constructor_list, free);
        free(self);
        *self_pointer = NULL;
    }
}

void
datatype_close(datatype_t *self) {
    self->is_closed = true;
}

bool
datatype_is_closed(datatype_t *self) {
    return self->is_closed;
}

void
datatype_add_data_constructor(datatype_t *self, word_t *name, size_t arity) {
    data_constructor_t *data_constructor = data_constructor_create(self, name, arity);
    list_push(self->data_constructor_list, data_constructor);
}
