#include "../index.h"
#include "../tests/index.h"

int
main(void) {
    // INTEGRATION TESTS

    test_word();
    test_value_stack();
    test_build_program();
    test_builtin_int();
    test_builtin_string();

    return 0;
}
