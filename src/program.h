#pragma once

typedef struct _program_t program_t;

program_t *program_create(size_t size);
void program_destroy(program_t **self_p);
