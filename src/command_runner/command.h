#pragma once

command_t *command_create(const char *name);
void command_free(command_t *self);
void command_destroy(command_t **self_ptr);

const char *command_name(command_t *self);
command_run_fn_t *command_run_fn(command_t *self);
