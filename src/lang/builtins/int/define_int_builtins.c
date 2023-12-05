#include "../../index.h"

void
define_int_builtins(vm_t *vm) {
    vm_define_primitive(vm, "int_print", _int_print);
    vm_define_primitive(vm, "int_equal", _int_equal);
    vm_define_primitive(vm, "int_greater", _int_greater);
    vm_define_primitive(vm, "int_lesser", _int_lesser);
    vm_define_primitive(vm, "int_greater_or_equal", _int_greater_or_equal);
    vm_define_primitive(vm, "int_lesser_or_equal", _int_lesser_or_equal);
    vm_define_primitive(vm, "int_add", _int_add);
    vm_define_primitive(vm, "int_sub", _int_sub);
    vm_define_primitive(vm, "int_mul", _int_mul);
}
