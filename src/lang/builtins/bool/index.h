#pragma once

void _true(const vm_t *vm);
void _false(const vm_t *vm);
void _bool_print(const vm_t *vm);
void _bool_dup(const vm_t *vm);
void _bool_drop(const vm_t *vm);
void _bool_equal(const vm_t *vm);
void _bool_not(const vm_t *vm);
void _bool_and(const vm_t *vm);
void _bool_or(const vm_t *vm);
void _if_else(const vm_t *vm);
void _if(const vm_t *vm);

void define_bool_builtins(vm_t *vm);
