#include "index.h"

struct _value_stack_t {
    size_t size;
    value_t *values;
    size_t cursor;
};

value_stack_t *
value_stack_create(size_t size) {
    value_stack_t *self = (value_stack_t *) calloc(1, sizeof(value_stack_t));
    self->size = size;
    self->values = (value_t *) calloc(size, sizeof(value_t));
    self->cursor = 0;
    return self;
}

void
value_stack_destroy(value_stack_t **self_p) {
    assert(self_p);
    if (*self_p) {
        value_stack_t *self = *self_p;
        free(self->values);
        free(self);
        *self_p = NULL;
    }
}

value_t
value_stack_pop(value_stack_t *self) {
    assert(self->cursor > 0);
    self->cursor--;
    return self->values[self->cursor];
}

void
value_stack_push(value_stack_t *self, value_t value) {
    self->values[self->cursor] = value;
    self->cursor++;
}
