#include "../../index.h"

void
define_bool_builtins(vm_t *vm) {
    vm_define_primitive(vm, "true", _true);
    vm_define_primitive(vm, "false", _false);
    vm_define_primitive(vm, "bool_print", _bool_print);
    vm_define_primitive(vm, "bool_dup", _bool_dup);
    vm_define_primitive(vm, "bool_not", _bool_not);
    vm_define_primitive(vm, "bool_and", _bool_and);
    vm_define_primitive(vm, "bool_or", _bool_or);
    vm_define_primitive(vm, "bool_choose", _bool_choose);
    vm_define_primitive(vm, "bool_when", _bool_when);
}
