#include "../../index.h"

void
_define(const vm_t *vm) {
    program_t *program = (program_t *) vm_value_stack_pop(vm);
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    word_program_set(word, program);
}

void
_claim(const vm_t *vm) {
    program_t *type_program = (program_t *) vm_value_stack_pop(vm);
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    word_type_program_set(word, type_program);
}

void
_apply(const vm_t *vm) {
    program_t *program = (program_t *) vm_value_stack_pop(vm);
    vm_load_program(vm, program);
}

void
_execute(const vm_t *vm) {
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    program_t *program = word_program(word);
    vm_load_program(vm, program);
}

void _dup(const vm_t *vm) {
    value_t value = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, value);
    vm_value_stack_push(vm, value);
}

void _drop(const vm_t *vm) {
    vm_value_stack_pop(vm);
}

void _swap(const vm_t *vm) {
    value_t second = vm_value_stack_pop(vm);
    value_t first = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, second);
    vm_value_stack_push(vm, first);
}

void _rot(const vm_t *vm) {
    value_t third = vm_value_stack_pop(vm);
    value_t second = vm_value_stack_pop(vm);
    value_t first = vm_value_stack_pop(vm);
    vm_value_stack_push(vm, second);
    vm_value_stack_push(vm, third);
    vm_value_stack_push(vm, first);
}
