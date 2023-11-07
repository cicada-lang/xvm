#include "command_runner/index.h"
#include "lang/index.h"
#include "lang/tests/index.h"

void self_test(void);

int
main(void) {
    command_runner_t *runner = command_runner_create(X_VERSION);

    self_test();

    command_runner_destroy(&runner);

    return 0;
}

void
self_test(void) {
    test_word();
    test_value_stack();
    test_build_program();
    test_builtin_int();
    test_builtin_string();
    test_utils();

    printf("\n");
}
