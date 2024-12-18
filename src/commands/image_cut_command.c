#include "index.h"
#include "../font_editor/index.h"

static int run(commander_t *commander);

// examples:
//     app image:cut button-10x10.chr 0 0 button-up-03x03.chr
//     app image:cut button-10x10.chr 3 0 button-down-03x03.chr

void
image_cut_command(commander_t *commander) {
    command_t *command = command_new("image:cut");
    command->description = "cut subimage from .chr image";
    command->run = run;
    commander_add(commander, command);
}

int
run(commander_t *commander) {
    char **argv = commander_rest_argv(commander);
    size_t argc = commander_rest_argc(commander);
    if (argc != 4) {
        printf("[cut-image] expect 4 arguments, given: %ld\n", argc);
        return 1;
    }

    char *input_path = argv[0];
    if (!string_ends_with(input_path, ".chr")) {
        printf("[cut-image] can only handle .chr file, input_path: %s\n", input_path);
        return 1;
    }

    char *output_path = argv[3];
    if (!string_ends_with(output_path, ".chr")) {
        printf("[cut-image] can only handle .chr file, output_path: %s\n", output_path);
        return 1;
    }

    uint8_t input_width = image_hex_width_from_path(input_path);
    uint8_t x = string_parse_hex(argv[1]);
    uint8_t y = string_parse_hex(argv[2]);
    uint8_t output_width = image_hex_width_from_path(output_path);
    uint8_t output_height = image_hex_height_from_path(output_path);

    file_t *input_file = file_open_or_fail(input_path, "rb");
    uint8_t * bytes = file_read_bytes(input_file);

    file_t *output_file = file_open_or_fail(output_path, "wb");
    size_t output_size = output_width * output_height * 8 * 8;
    uint8_t *subimage = chr_subimage(
        bytes,
        input_width,
        x, y,
        output_width,
        output_height);
    file_write_bytes(output_file, subimage, output_size);

    return 0;
}
