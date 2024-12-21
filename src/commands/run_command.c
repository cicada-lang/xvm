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
    char **paths = commander_rest_argv(commander);
    file_t *input = file_open_or_fail(paths[0], "r");
    blob_t *blob = xasm_asm(file_read_string(input));
    xemu_emu(blob);
    return 0;
}
