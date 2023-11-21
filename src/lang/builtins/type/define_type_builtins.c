#include "../../index.h"

void
define_type_builtins(vm_t *vm) {
    vm_define_primitive(vm, "type_t", _type_t);
    vm_define_primitive(vm, "type_print", _type_print);
    vm_define_primitive(vm, "type_claim_by_arity", _type_claim_by_arity);
}
