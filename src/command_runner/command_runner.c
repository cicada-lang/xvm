#include "index.h"

struct _command_runner_t {
    const char *version;
    int argc;
    const char **argv;
    list_t *command_list;
};

command_runner_t *
command_runner_create(const char *version, int argc, const char **argv) {
    command_runner_t *self = allocate(sizeof(command_runner_t));
    self->version = version;
    self->argc = argc;
    self->argv = argv;
    self->command_list = list_create();
    return self;
}

void
command_runner_destroy(command_runner_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        command_runner_t *self = *self_ptr;
        list_destroy(&self->command_list, (list_item_free_fn_t *) command_free);
        free(self);
        *self_ptr = NULL;
    }
}

void
command_runner_add_command(const command_runner_t *self, command_t *command) {
    list_push(self->command_list, command);
}

void
command_runner_mount(const command_runner_t *self, command_plugin_fn_t *plugin_fn) {
    (*plugin_fn)(self);
}

static const command_t *
command_runner_default_command(const command_runner_t *self) {
    command_t *command = list_start(self->command_list);
    while (command) {
        if (strcmp(command->name, "default") == 0)
            return command;

        command = list_next(self->command_list);
    }

    return NULL;
}

static void
command_runner_help(const command_runner_t *self) {
    printf("commands:\n");
    command_t *command = list_start(self->command_list);
    while (command) {
        printf("  %s", command->name);
        if (command->description)
            printf(" -- %s", command->description);

        printf("\n");
        command = list_next(self->command_list);
    }
}

int
command_runner_run(const command_runner_t *self) {
    const char *name = self->argv[1];
    const char **args = self->argv + 1;

    if (!name) {
        const command_t *default_command = command_runner_default_command(self);
        if (default_command) {
            return (*default_command->run_fn)(args);
        } else {
            command_runner_help(self);
            return 0;
        }
    }

    command_t *command = list_start(self->command_list);
    while (command) {
        if (strcmp(command->name, name) == 0)
            return (*command->run_fn)(args);

        command = list_next(self->command_list);
    }

    printf("command not found: %s\n", name);
    return 1;
}
