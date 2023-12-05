#include "../../index.h"

void
define_int_builtins(vm_t *vm) {
    vm_define_primitive(vm, "int_print", _int_print);
    vm_define_primitive(vm, "eq", _eq);
    vm_define_primitive(vm, "greater", _greater);
    vm_define_primitive(vm, "lesser", _lesser);
    vm_define_primitive(vm, "greater_or_equal", _greater_or_equal);
    vm_define_primitive(vm, "lteq", _lteq);
    vm_define_primitive(vm, "add", _add);
    vm_define_primitive(vm, "sub", _sub);
    vm_define_primitive(vm, "mul", _mul);
}
