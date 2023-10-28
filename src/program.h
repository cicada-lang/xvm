#pragma once

// Program contains a byte array with dynamic length.

typedef struct _program_t program_t;

program_t *program_create();
void program_destroy(program_t **self_p);
// size_t program_byte_size(program_t *self);
// value_t program_fetch_value(program_t *self, size_t index);
// void program_append_bytes(program_t *self, const byte_t *bytes, size_t size);
// void program_append_call(program_t *self, const char *name);
// void program_append_value(program_t *self, const char *name);
