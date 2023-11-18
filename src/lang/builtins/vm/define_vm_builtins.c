#include "../../index.h"

void
define_vm_builtins(vm_t *vm) {
    vm_define_primitive(vm, "define", _define);
    vm_define_primitive(vm, "swap", _swap);
    vm_define_primitive(vm, "rot", _rot);
}
