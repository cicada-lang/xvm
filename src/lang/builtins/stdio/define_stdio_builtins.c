#include "../../index.h"

void
define_stdio_builtins(vm_t *vm) {
    vm_define_primitive(vm, "newline", _newline);
}
