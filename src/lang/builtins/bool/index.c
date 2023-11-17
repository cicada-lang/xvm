#include "../../index.h"

void _true(const vm_t *vm) {
    vm_value_stack_push(vm, true);
}

void _false(const vm_t *vm) {
    vm_value_stack_push(vm, false);
}

void _bool_print(const vm_t *vm) {
    bool value = vm_value_stack_pop(vm);
    if (value) {
        printf("true");
    } else {
        printf("false");
    }
}

void _bool_not(const vm_t *vm) {
    bool x = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, !x);
}

void _bool_and(const vm_t *vm) {
    bool x = vm_value_stack_pop(vm);
    bool y = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, x && y);
}

void _bool_or(const vm_t *vm) {
    bool x = vm_value_stack_pop(vm);
    bool y = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, x || y);
}
