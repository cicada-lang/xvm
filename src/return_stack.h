#pragma once

typedef struct _return_stack_t return_stack_t;

return_stack_t *return_stack_create(size_t size);
void return_stack_destroy(return_stack_t **self_p);
return_frame_t *return_stack_pop(return_stack_t *self);
void return_stack_push(return_stack_t *self, return_frame_t *return_frame);
