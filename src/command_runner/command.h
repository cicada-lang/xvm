#pragma once

command_t *command_create(const char *name);
void command_destroy(command_t **self_ptr);
