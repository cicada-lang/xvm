#include "index.h"

struct _datatype_t {
    const word_t *name;
    list_t *data_constructor_list;
};

datatype_t *
datatype_create(const word_t *name) {
    datatype_t *self = allocate(sizeof(datatype_t));
    self->name = name;
    self->data_constructor_list = list_create();
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
