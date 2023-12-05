#include "../index.h"

void
define_all_builtins(vm_t *vm) {
    define_stdio_builtins(vm);
    define_assert_builtins(vm);
    define_bool_builtins(vm);
    define_int_builtins(vm);
    define_string_builtins(vm);
    define_word_builtins(vm);
    define_vm_builtins(vm);
}
