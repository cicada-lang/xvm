#include "index.h"
#include "../lang/tests/index.h"

static int run(char **args);

void
default_version_command(const commander_t *runner) {
    command_t *command = command_new("version");
    command->description = "print version";
    command->run = run;
    commander_add_command(runner, command);
}

int
run(char **args) {
    (void) args;

    printf("%s\n", X_VERSION);

    return 0;
}
