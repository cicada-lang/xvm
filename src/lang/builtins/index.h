#pragma once

void _newline(const vm_t *vm);

void _int_print(const vm_t *vm);
void _int_dup(const vm_t *vm);
void _int_add(const vm_t *vm);
void _int_sub(const vm_t *vm);
void _int_mul(const vm_t *vm);

void _string_print(const vm_t *vm);
void _string_dup(const vm_t *vm);
void _string_length(const vm_t *vm);
void _string_append(const vm_t *vm);
