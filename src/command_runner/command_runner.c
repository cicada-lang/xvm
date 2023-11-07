#include "index.h"

struct _command_runner_t {
    const char *version;
    list_t *command_list;
};

command_runner_t *
command_runner_create(const char *version) {
    command_runner_t *self = allocate(sizeof(command_runner_t));
    self->version = version;
    self->command_list = list_create();
    return self;
}
