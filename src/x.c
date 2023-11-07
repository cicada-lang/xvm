#include "lang/index.h"
#include "lang/tests/index.h"

int
main(void) {
    test_word();
    test_value_stack();
    test_build_program();
    test_builtin_int();
    test_builtin_string();
    test_utils();

    printf("\n");

    return 0;
}
