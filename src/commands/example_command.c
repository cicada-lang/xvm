#include "index.h"
#include "../example_button/index.h"
#include "../example_blending/index.h"

static int run(commander_t *commander);

void
example_command(commander_t *commander) {
    command_t *command = command_new("example");
    command->description = "run example programs";
    command->run = run;
    commander_add(commander, command);
}

static void
print_known_examples(void) {
    printf("[example] known examples: button, blending\n");
}

int
run(commander_t *commander) {
    char **names = commander_rest_argv(commander);
    char *name = names[0];

    if (!name) {
        printf("[example] expect a given example\n");
        print_known_examples();
        return 1;
    }

    if (string_equal(name, "button")) {
        example_button_start();
        return 0;
    }

    if (string_equal(name, "blending")) {
        example_blending_start();
        return 0;
    }

    printf("[example] unknown example name: %s\n", name);
    print_known_examples();
    return 1;
}
