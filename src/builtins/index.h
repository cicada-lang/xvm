#pragma once

void _newline(vm_t *vm);

void _int_print(vm_t *vm);
void _int_dup(vm_t *vm);
void _int_mul(vm_t *vm);

void _string_print(vm_t *vm);
void _string_dup(vm_t *vm);
void _string_length(vm_t *vm);
void _string_append(vm_t *vm);
