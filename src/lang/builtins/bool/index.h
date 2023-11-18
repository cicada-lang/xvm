#pragma once

void _true(const vm_t *vm);
void _false(const vm_t *vm);
void _bool_print(const vm_t *vm);
void _bool_dup(const vm_t *vm);
void _bool_not(const vm_t *vm);
void _bool_and(const vm_t *vm);
void _bool_or(const vm_t *vm);
void _bool_choose(const vm_t *vm);

void define_bool_builtins(vm_t *vm);
