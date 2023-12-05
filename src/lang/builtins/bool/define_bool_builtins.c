#include "../../index.h"

void
define_bool_builtins(vm_t *vm) {
    vm_define_primitive(vm, "true", _true);
    vm_define_primitive(vm, "false", _false);
    vm_define_primitive(vm, "bool_print", _bool_print);
    vm_define_primitive(vm, "not", _not);
    vm_define_primitive(vm, "and", _and);
    vm_define_primitive(vm, "or", _or);
    vm_define_primitive(vm, "if_else", _if_else);
    vm_define_primitive(vm, "if", _if);
}
