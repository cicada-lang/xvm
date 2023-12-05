#include "../../index.h"

void
define_local_variable_builtins(vm_t *vm) {
    vm_define_primitive(vm, "set", _set);
    vm_define_primitive(vm, "get", _get);
}
