#pragma once

typedef struct _command_runner_t command_runner_t;
typedef struct _command_t command_t;

typedef void (command_plugin_fn_t)(const command_runner_t *runner);
typedef void (command_run_fn_t)(const char **args);
