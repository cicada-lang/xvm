#include "../../index.h"

void
define_int_builtins(vm_t *vm) {
    vm_define_primitive(vm, "int_print", _int_print);
    vm_define_primitive(vm, "int_dup", _int_dup);
    vm_define_primitive(vm, "int_equal", _int_equal);
    vm_define_primitive(vm, "int_add", _int_add);
    vm_define_primitive(vm, "int_sub", _int_sub);
    vm_define_primitive(vm, "int_mul", _int_mul);
}
