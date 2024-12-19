#include "index.h"

static int run(commander_t *commander);

void
run_command(commander_t *commander) {
    command_t *command = command_new("run");
    command->description = "run a .xasm file";
    command->run = run;
    commander_add(commander, command);
}

int
run(commander_t *commander) {
    (void) commander;

    printf("TODO\n");

    return 0;
}
