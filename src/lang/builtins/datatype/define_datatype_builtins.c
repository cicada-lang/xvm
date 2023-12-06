#include "../../index.h"

void
define_datatype_builtins(vm_t *vm) {
    vm_define_primitive(vm, "datatype_define", _datatype_define);
    vm_define_primitive(vm, "datatype_close", _datatype_close);
    vm_define_primitive(vm, "arity_case", _arity_case);
}
