#include "index.h"
#include "../lang/index.h"

static int run(char **args);

void
run_command(const commander_t *runner) {
    command_t *command = command_new("run");
    command->description = "run a file";
    command->run = run;
    commander_add(runner, command);
}

static int run_file(const char *file_name);

int
run(char **args) {
    char **file_names = ++args;
    while (*file_names) {
        int status_code = run_file(*file_names);
        if (status_code != 0) return status_code;
        file_names++;
    }

    return 0;
}

int
run_file(const char *file_name) {
    if (!file_name) {
        printf("[run] I expect a file name.\n");
        return 1;
    }

    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("[run] I file to open file: %s\n", file_name);
        return 1;
    }

    char *code = file_read(file);

    vm_t *vm = vm_init();
    vm_interpret_code(vm, code);
    vm_destroy(&vm);

    fclose(file);
    return 0;
}
