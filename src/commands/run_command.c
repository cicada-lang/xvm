#include "index.h"
#include "../lang/index.h"

static int run(const char **args);

void
run_command(const command_runner_t *runner) {
    command_t *command = command_create("run");
    command->description = "run a file";
    command->run = run;
    command_runner_add_command(runner, command);
}

int
run(const char **args) {
    const char *file_name = args[1];
    if (!file_name) {
        printf("[run] I expect a file name.\n");
        return 1;
    }

    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("[run] I file to open file: %s\n", file_name);
        return 1;
    }

    size_t code_max_length  = 10 * 1000 * 1000;
    char *code = allocate(code_max_length);

    while (fgets(code, 1000, file)) {
        vm_t *vm = vm_init();
        vm_interpret_code(vm, code);
        vm_destroy(&vm);
    }

    fclose(file);

    return 0;
}
