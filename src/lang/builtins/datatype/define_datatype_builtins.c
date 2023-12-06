#include "../../index.h"

void
define_datatype_builtins(vm_t *vm) {
    vm_define_primitive(vm, "datatype_define", _datatype_define);
}
