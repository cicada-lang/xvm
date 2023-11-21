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
_type_print(const vm_t *vm) {
    type_t *type = (type_t *) vm_value_stack_pop(vm);
    if (type_is_type_var(type)) {
        printf("%s", type_var_name(type));
        type_destroy(&type);
    } else if (type_is_type_term(type)) {
        // TODO Also print prepend args.
        for (size_t i = 0; i < type_term_arity(type); i++) {
            printf("%s ", type_term_name(type_term_type_arg_get(type, i)));
        }

        printf("%s", type_term_name(type));
        type_destroy(&type);
    }
}
