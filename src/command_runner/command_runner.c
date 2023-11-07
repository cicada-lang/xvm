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
command_runner_mount(command_runner_t *self, command_plugin_fn_t *plugin_fn) {
    (*plugin_fn)(self);
}

void
command_runner_run(command_runner_t *self) {
    const char *name = self->argv[1];

    if (name) {
        printf("command name: %s\n", name);
    }

    command_t *command = list_start(self->command_list);
    while (command) {
        if (strcmp(command_name(command), name) == 0) {
            (*command_run_fn(command))(self->argv++);
            return;
        }

        command = list_next(self->command_list);
    }
}
