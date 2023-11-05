#pragma once

interpreter_t *interpreter_create(vm_t *vm, list_t *token_list);
void interpreter_destroy(interpreter_t **self_ptr);
