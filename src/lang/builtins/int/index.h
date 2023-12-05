#pragma once

void _int_print(const vm_t *vm);
void _int_equal(const vm_t *vm);
void _greater(const vm_t *vm);
void _lesser(const vm_t *vm);
void _greater_or_equal(const vm_t *vm);
void _lesser_or_equal(const vm_t *vm);
void _add(const vm_t *vm);
void _sub(const vm_t *vm);
void _mul(const vm_t *vm);

void define_int_builtins(vm_t *vm);
