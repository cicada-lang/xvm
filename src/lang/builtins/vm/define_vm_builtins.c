#include "../../index.h"

void
define_vm_builtins(vm_t *vm) {
    vm_define_primitive(vm, "define", _define);
    vm_define_primitive(vm, "claim", _claim);
    vm_define_primitive(vm, "dup", _dup);
    vm_define_primitive(vm, "drop", _drop);
    vm_define_primitive(vm, "swap", _swap);
    vm_define_primitive(vm, "rot", _rot);
}
