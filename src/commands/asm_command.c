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
    char *input_file_name = paths[0];
    char *output_file_name = paths[1];
    file_t *input_file = file_open_or_fail(input_file_name, "r");
    const char *string = file_read_string(input_file);
    xasm_t *xasm = xasm_new();
    xasm_asm(xasm, string);
    blob_t *blob = xasm_dump(xasm);
    file_t *output_file = file_open_or_fail(output_file_name, "w");
    file_write_blob(output_file, blob);
    return 0;
}
