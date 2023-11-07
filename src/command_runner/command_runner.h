#pragma once

command_runner_t *command_runner_create(const char *version);
void command_runner_destroy(command_runner_t **self_ptr);

void command_runner_mount(command_runner_t *self, command_plugin_fn_t *plugin_fn);
