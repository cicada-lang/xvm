#pragma once

void _int_print(const vm_t *vm);
void _eq(const vm_t *vm);
void _gt(const vm_t *vm);
void _lt(const vm_t *vm);
void _gteq(const vm_t *vm);
void _lteq(const vm_t *vm);
void _add(const vm_t *vm);
void _sub(const vm_t *vm);
void _mul(const vm_t *vm);

void define_int_builtins(vm_t *vm);
