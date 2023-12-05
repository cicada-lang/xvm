#include "../../index.h"

void _set(const vm_t *vm) {
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    value_t value = vm_value_stack_pop(vm);
    frame_t *frame = vm_return_stack_pop(vm);
    frame_set_local_variable(frame, word, value);
    vm_return_stack_push(vm, frame);
}

void _get(const vm_t *vm) {
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    frame_t *frame = vm_return_stack_pop(vm);
    value_t value = frame_get_local_variable(frame, word);
    vm_return_stack_push(vm, frame);
    vm_value_stack_push(vm, value);
}
