#include "index.h"

static int run(commander_t *commander);

void
emu_command(commander_t *commander) {
    command_t *command = command_new("emu");
    command->description = "emulate a .rom file";
    command->run = run;
    commander_add(commander, command);
}

int
run(commander_t *commander) {
    (void) commander;

    printf("TODO\n");

    return 0;
}
