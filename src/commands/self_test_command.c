#include "index.h"
#include "../lang/tests/index.h"

void run(const char **args);

void
self_test_command(const command_runner_t *runner) {
    command_t *command = command_create("self-test");
    command->run_fn = run;
    command_runner_add(runner, command);
}

void
run(const char **args) {
    (void) args;

    test_word();
    test_value_stack();
    test_build_program();
    test_builtin_int();
    test_builtin_string();
    test_utils();

    printf("\n");
}
