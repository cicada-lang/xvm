#pragma once

value_stack_t *value_stack_new(size_t size);
void value_stack_destroy(value_stack_t **self_pointer);

value_t value_stack_pop(value_stack_t *self);
void value_stack_push(value_stack_t *self, value_t value);
bool value_stack_is_empty(value_stack_t *self);
