#include "../../index.h"

void
define_type_builtins(vm_t *vm) {
    vm_define_primitive(vm, "type_t", _type_t);
}
