#include "../../index.h"

void _type_t(const vm_t *vm) {
    type_t *the_type_t =  type_term_create("type_t", 0);
    vm_value_stack_push(vm, (value_t) the_type_t);
}

// void _type_claim_by_arity(const vm_t *vm) {
//     word_t *word =  vm_value_stack_pop(vm);
//     size_t arity =  vm_value_stack_pop(vm);
// }
