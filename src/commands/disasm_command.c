#include "index.h"

static int run(commander_t *commander);

void
disasm_command(commander_t *commander) {
    command_t *command = command_new("disasm");
    command->description = "disassemble a .xrom file with .lexi";
    command->run = run;
    commander_add(commander, command);
}

int
run(commander_t *commander) {
    char **paths = commander_rest_argv(commander);
    file_t *input = file_open_or_fail(paths[0], "r");
    xdisasm_disasm(file_read_blob(input));
    return 0;
}
