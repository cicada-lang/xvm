#include "../../index.h"

void
define_assert_builtins(vm_t *self) {
    vm_define_primitive(self, "assert", _assert);
}
