#pragma once

typedef struct _return_frame_t return_frame_t;

return_frame_t *return_frame_create(const program_t *program);
void return_frame_destroy(return_frame_t **self_p);
