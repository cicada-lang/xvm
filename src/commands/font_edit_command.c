#include "index.h"
#include "../font_editor/index.h"

static int run(commander_t *commander);

void
font_edit_command(commander_t *commander) {
    command_t *command = command_new("font:edit");
    command->description = "edit a .hex font file";
    command->run = run;
    commander_add(commander, command);
}

int
run(commander_t *commander) {
    char **paths = commander_rest_argv(commander);
    char *path = paths[0];

    file_t *file = file_open_or_fail(path, "r");
    font_t *font = font_from_hex_file(file);
    font_editor_start(font);
    return 1;
}
