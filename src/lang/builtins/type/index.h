#pragma once

void _type_t(const vm_t *vm);
void _type_format(const vm_t *vm);
void _type_print(const vm_t *vm);
void _type_claim_by_arity(const vm_t *vm);

void define_type_builtins(vm_t *vm);
