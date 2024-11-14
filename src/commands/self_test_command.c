#include "index.h"
#include "../lang/tests/index.h"

static int run(char **args);

void
self_test_command(const commander_t *runner) {
    command_t *command = command_new("self-test");
    command->description = "run self test";
    command->run = run;
    commander_add_command(runner, command);
}

int
run(char **args) {
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
