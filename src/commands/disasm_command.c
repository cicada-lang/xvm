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

    char *lexi_input_name = string_append(paths[0], ".lexi");
    file_t *lexi_input = file_open_or_fail(lexi_input_name, "r");

    xdisasm_disasm(file_read_blob(input), file_read_blob(lexi_input));
    return 0;
}
