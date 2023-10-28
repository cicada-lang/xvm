#pragma once

// Program contains a byte array with dynamic length.

typedef struct _program_t program_t;

program_t *program_create();
void program_destroy(program_t **self_p);
