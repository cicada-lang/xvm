#pragma once

typedef int (command_run_fn_t)(const char **args);

typedef struct {
    const char *name;
    const char *description;
    const char *help;
    command_run_fn_t *run_fn;
} command_t;

typedef struct _command_runner_t command_runner_t;

typedef void (command_plugin_fn_t)(const command_runner_t *runner);
