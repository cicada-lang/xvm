#include "../../index.h"

void _datatype_define(const vm_t *vm) {
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    datatype_t *datatype = datatype_create(word);
    vm_value_stack_push(vm, (value_t) datatype);
}
