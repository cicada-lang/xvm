#pragma once

#include "../deps.h"
#include "../utils/index.h"
#include "../commander/index.h"

void run_command(const commander_t *runner);
void repl_command(const commander_t *runner);
void self_test_command(const commander_t *runner);
