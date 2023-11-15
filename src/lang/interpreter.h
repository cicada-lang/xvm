#pragma once

interpreter_t *interpreter_create(const vm_t *vm, const char *code);
void interpreter_destroy(interpreter_t **self_pointer);

void interpreter_interpret(interpreter_t *self);
