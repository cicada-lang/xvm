#pragma once

void _true(const vm_t *vm);
void _false(const vm_t *vm);
void _bool_print(const vm_t *vm);
void _bool_equal(const vm_t *vm);
void _not(const vm_t *vm);
void _and(const vm_t *vm);
void _or(const vm_t *vm);
void _if_else(const vm_t *vm);
void _if(const vm_t *vm);

void define_bool_builtins(vm_t *vm);
