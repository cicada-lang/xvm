#include "index.h"
#include "../lang/index.h"

static int run(char **args);

void
repl_command(const command_runner_t *runner) {
    command_t *command = command_new("repl");
    command->description = "start the read-eval-print-loop";
    command->run = run;
    command_runner_add_command(runner, command);
}

int
run(char **args) {
    (void) args;

    printf("%s\n", X_VERSION);

    return 0;
}
