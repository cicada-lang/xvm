#include "../../index.h"

void _word_print(const vm_t *vm) {
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    printf("%s", word_name(word));
}

void _word_dup(const vm_t *vm) {
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    vm_value_stack_push(vm, (value_t) word);
    vm_value_stack_push(vm, (value_t) word);
}

void _word_drop(const vm_t *vm) {
    vm_value_stack_pop(vm);
}

void _word_equal(const vm_t *vm) {
    word_t *right = (word_t *) vm_value_stack_pop(vm);
    word_t *left = (word_t *) vm_value_stack_pop(vm);
    vm_value_stack_push(vm, right == left);
}
