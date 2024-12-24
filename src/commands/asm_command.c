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


    xasm_t *xasm = xasm_new();
    xasm_run(xasm, file_read_string(input));
    blob_t *blob = xasm_dump(xasm);
    file_write_blob(output, blob);

    char *lexi_output_name = string_append(paths[1], ".lexi");
    file_t *lexi_output = file_open_or_fail(lexi_output_name, "w");
    lexicon_print(xasm->lexicon, lexi_output);

    return 0;
}
