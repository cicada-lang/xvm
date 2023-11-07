#include "index.h"

struct _command_t {
    char *name;
    char *description;
    char *help;
    command_run_fn_t *run_fn;
};
