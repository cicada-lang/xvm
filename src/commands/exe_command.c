#include "index.h"

static int run(commander_t *commander);

void
exe_command(commander_t *commander) {
    command_t *command = command_new("exe");
    command->description = "execute a .xrom file";
    command->run = run;
    commander_add(commander, command);
}

int
run(commander_t *commander) {
    (void) commander;

    printf("TODO\n");

    return 0;
}
