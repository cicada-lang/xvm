#include "../index.h"

void
define_all_builtins(vm_t *self) {
    define_stdio_builtins(self);
    define_assert_builtins(self);
    define_bool_builtins(self);
    define_int_builtins(self);
    define_string_builtins(self);
    define_word_builtins(self);
    define_vm_builtins(self);
}
