#include "../../index.h"

void _datatype_define(const vm_t *vm) {
    word_t *name = (word_t *) vm_value_stack_pop(vm);
    datatype_t *datatype = datatype_new(name);
    vm_value_stack_push(vm, (value_t) datatype);
}

void _datatype_close(const vm_t *vm) {
    datatype_t *datatype = (datatype_t *) vm_value_stack_pop(vm);
    datatype_close(datatype);
}

void _arity_case(const vm_t *vm) {
    size_t arity = vm_value_stack_pop(vm);
    word_t *name = (word_t *) vm_value_stack_pop(vm);
    datatype_t *datatype = (datatype_t *) vm_value_stack_pop(vm);
    datatype_add_data_constructor(datatype, name, arity);
    vm_value_stack_push(vm, (value_t) datatype);
}
