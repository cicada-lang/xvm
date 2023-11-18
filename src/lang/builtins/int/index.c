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

void _int_drop(const vm_t *vm) {
    vm_value_stack_pop(vm);
}

void _int_equal(const vm_t *vm) {
    int_t right = vm_value_stack_pop(vm);
    int_t left = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, left == right);
}

void _int_greater(const vm_t *vm) {
    int_t right = vm_value_stack_pop(vm);
    int_t left = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, left > right);
}

void _int_lesser(const vm_t *vm) {
    int_t right = vm_value_stack_pop(vm);
    int_t left = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, left < right);
}

void _int_greater_or_equal(const vm_t *vm) {
    int_t right = vm_value_stack_pop(vm);
    int_t left = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, left >= right);
}

void _int_lesser_or_equal(const vm_t *vm) {
    int_t right = vm_value_stack_pop(vm);
    int_t left = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, left <= right);
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
