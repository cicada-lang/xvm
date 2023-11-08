#include "index.h"
#include "../lang/tests/index.h"

static int run(const char **args);

void
repl_command(const command_runner_t *runner) {
    command_t *command = command_create("repl");
    command->run_fn = run;
    command_runner_add_command(runner, command);
}

int
run(const char **args) {
    (void) args;

    printf("%s\n", X_VERSION);

    return 0;
}
