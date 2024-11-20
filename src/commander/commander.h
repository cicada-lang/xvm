#pragma once

commander_t *commander_new(const char *name, const char *version, int argc, char **argv);
void commander_destroy(commander_t **self_pointer);

void commander_add(const commander_t *self, command_t *command);
void commander_use(const commander_t *self, command_plugin_t *plugin);
void commander_help(const commander_t *self);
int commander_run(const commander_t *self);
