#include "../../index.h"

void
define_vm_builtins(vm_t *self) {
    vm_define_primitive(self, "define", _define);
}
