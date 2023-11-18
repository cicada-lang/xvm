#include "../../index.h"

void _int_print(const vm_t *vm) {
    int_t value = vm_value_stack_pop(vm);
    printf("%ld", value);
}

void _int_dup(const vm_t *vm) {
    int_t value = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, value);
    vm_value_stack_push(vm, value);
}

void _int_equal(const vm_t *vm) {
    int_t right = vm_value_stack_pop(vm);
    int_t left = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, right == left);
}

void _int_add(const vm_t *vm) {
    int_t x = vm_value_stack_pop(vm);
    int_t y = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, x + y);
}

void _int_sub(const vm_t *vm) {
    int_t x = vm_value_stack_pop(vm);
    int_t y = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, y - x);
}

void _int_mul(const vm_t *vm) {
    int_t x = vm_value_stack_pop(vm);
    int_t y = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, x * y);
}
