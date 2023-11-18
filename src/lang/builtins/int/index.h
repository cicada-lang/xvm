#pragma once

void _int_print(const vm_t *vm);
void _int_dup(const vm_t *vm);
void _int_add(const vm_t *vm);
void _int_sub(const vm_t *vm);
void _int_mul(const vm_t *vm);

void define_int_builtins(vm_t *vm);
