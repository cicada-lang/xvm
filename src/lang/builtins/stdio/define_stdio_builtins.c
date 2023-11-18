#include "../../index.h"

void
define_stdio_builtins(vm_t *self) {
    vm_define_primitive(self, "newline", _newline);
}
