#include "index.h"

struct _value_stack_t {
    size_t size;
    value_t *values;
};

value_stack_t *
value_stack_create(size_t size) {
    value_stack_t *self = (value_stack_t *) calloc(1, sizeof(value_stack_t));
    self->values = (value_t *) calloc(size, sizeof(value_t));
    return self;
}

void
value_stack_destroy(value_stack_t **self_p) {
    assert (self_p);
    if (*self_p) {
        value_stack_t *self = *self_p;
        free(self->values);
        free(self);
        *self_p = NULL;
    }
}
