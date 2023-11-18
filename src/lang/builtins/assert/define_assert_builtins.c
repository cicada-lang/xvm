#include "../../index.h"

void
define_assert_builtins(vm_t *vm) {
    vm_define_primitive(vm, "assert", _assert);
}
