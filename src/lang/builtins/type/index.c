#include "../../index.h"

void _type_t(const vm_t *vm) {
    type_t *the_type_t =  type_term_create("type_t", 0);
    vm_value_stack_push(vm, (value_t) the_type_t);
}

void _type_claim_by_arity(const vm_t *vm) {
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    size_t arity = vm_value_stack_pop(vm);
    word_type_constructor_set(word, type_constructor_create(arity));
}

void
_type_format(const vm_t *vm) {
    type_t *type = (type_t *) vm_value_stack_pop(vm);
    if (type_is_type_var(type)) {
        // vm_value_stack_push(vm, type_var_name(type));
    } else if (type_is_type_term(type)) {
        // TODO Also print prepend args.
        // vm_value_stack_push(vm, type_term_name(type));
    }
}

void
_type_print(const vm_t *vm) {
    _type_format(vm);
    _string_print(vm);
}
