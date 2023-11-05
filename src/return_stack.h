#pragma once

return_stack_t *return_stack_create(size_t size);
void return_stack_destroy(return_stack_t **self_ptr);

frame_t *return_stack_pop(return_stack_t *self);
void return_stack_push(return_stack_t *self, frame_t *frame);
bool return_stack_empty_p(return_stack_t *self);
