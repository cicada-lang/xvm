#include "index.h"

struct _command_runner_t {
    size_t version;
    list_t *command_list;
};
