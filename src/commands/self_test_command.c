#include "index.h"
#include "../lang/tests/index.h"

static int run(const char **args);

void
self_test_command(const command_runner_t *runner) {
    command_t *command = command_create("self-test");
    command->description = "run self test";
    command->run = run;
    command_runner_add_command(runner, command);
}

int
run(const char **args) {
    (void) args;

    printf("<self-test>\n");

    test_word();
    test_value_stack();
    test_build_program();
    test_builtin_int();
    test_builtin_string();
    test_utils();

    printf("</self-test>\n");
    printf("\n");

    return 0;
}
