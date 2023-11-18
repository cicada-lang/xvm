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

void _bool_dup(const vm_t *vm) {
    bool x = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, x);
    vm_value_stack_push(vm, x);
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

void _bool_choose(const vm_t *vm) {
    program_t *on_false_program = (program_t *) vm_value_stack_pop(vm);
    program_t *on_true_program = (program_t *) vm_value_stack_pop(vm);
    bool target = vm_value_stack_pop(vm);
    if (target) {
        vm_load_program(vm, on_true_program);
    } else {
        vm_load_program(vm, on_false_program);
    }
}

void _bool_when(const vm_t *vm) {
    program_t *on_true_program = (program_t *) vm_value_stack_pop(vm);
    bool target = vm_value_stack_pop(vm);
    if (target) {
        vm_load_program(vm, on_true_program);
    }
}
