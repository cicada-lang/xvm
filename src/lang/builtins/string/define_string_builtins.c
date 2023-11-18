#include "../../index.h"

void
define_string_builtins(vm_t *vm) {
    vm_define_primitive(vm, "string_print", _string_print);
    vm_define_primitive(vm, "string_dup", _string_dup);
    vm_define_primitive(vm, "string_drop", _string_drop);
    vm_define_primitive(vm, "string_equal", _string_equal);
    vm_define_primitive(vm, "string_length", _string_length);
    vm_define_primitive(vm, "string_append", _string_append);
}
