#pragma once

command_runner_t *command_runner_create(const char *name, const char *version, int argc, const char **argv);
void command_runner_destroy(command_runner_t **self_ptr);

void command_runner_add_command(const command_runner_t *self, command_t *command);
void command_runner_mount(const command_runner_t *self, command_plugin_fn_t *plugin_fn);
int command_runner_run(const command_runner_t *self);
