#pragma once

void _int_print(const vm_t *vm);
void _int_equal(const vm_t *vm);
void _int_greater(const vm_t *vm);
void _int_lesser(const vm_t *vm);
void _int_greater_or_equal(const vm_t *vm);
void _int_lesser_or_equal(const vm_t *vm);
void _int_add(const vm_t *vm);
void _int_sub(const vm_t *vm);
void _int_mul(const vm_t *vm);

void define_int_builtins(vm_t *vm);
