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
    char **paths = commander_rest_argv(commander);
    file_t *input = file_open_or_fail(paths[0], "r");
    file_t *output = file_open_or_fail(paths[1], "w");
    blob_t *blob = xasm_asm(file_read_string(input));
    file_write_blob(output, blob);
    return 0;
}
