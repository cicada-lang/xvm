#include "index.h"

struct _value_stack_t {
    size_t size;
    value_t *values;
    size_t cursor;
};

value_stack_t *
value_stack_create(size_t size) {
    value_stack_t *self = allocate(sizeof(value_stack_t));
    self->size = size;
    self->values = allocate_array(size, sizeof(value_t));
    self->cursor = 0;
    return self;
}

void
value_stack_destroy(value_stack_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        value_stack_t *self = *self_ptr;
        free(self->values);
        free(self);
        *self_ptr = NULL;
    }
}

value_t
value_stack_pop(value_stack_t *self) {
    assert(self->cursor > 0);
    self->cursor--;
    value_t value = self->values[self->cursor];
    return value;
}

void
value_stack_push(value_stack_t *self, value_t value) {
    self->values[self->cursor] = value;
    self->cursor++;
}

bool
value_stack_empty_p(value_stack_t *self) {
    return self->cursor == 0;
}
