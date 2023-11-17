#include "../../index.h"

void
_define(const vm_t *vm) {
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    program_t *program = (program_t *) vm_value_stack_pop(vm);
    word_program_set(word, program);
}
