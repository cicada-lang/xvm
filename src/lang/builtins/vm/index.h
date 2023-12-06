#pragma once

void _define(const vm_t *vm);
void _claim(const vm_t *vm);
void _apply(const vm_t *vm);
void _execute(const vm_t *vm);
void _dup(const vm_t *vm);
void _drop(const vm_t *vm);
void _swap(const vm_t *vm);
void _rot(const vm_t *vm);

void define_vm_builtins(vm_t *vm);
