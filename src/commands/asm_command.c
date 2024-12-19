#include "index.h"

static int run(commander_t *commander);

void
asm_command(commander_t *commander) {
    command_t *command = command_new("asm");
    command->description = "assemble a .xasm file";
    command->run = run;
    commander_add(commander, command);
}

int
run(commander_t *commander) {
    (void) commander;

    printf("TODO\n");

    return 0;
}
