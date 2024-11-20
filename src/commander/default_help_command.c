#include "index.h"
#include "../lang/tests/index.h"

static int run_with_runner(char **args, const commander_t *runner);

void
default_help_command(const commander_t *runner) {
    command_t *command = command_new("help");
    command->description = "print help message";
    command->run_with_runner = run_with_runner;
    commander_add(runner, command);
}

int
run_with_runner(char **args, const commander_t *runner) {
    (void) args;

    commander_help(runner);

    return 0;
}
