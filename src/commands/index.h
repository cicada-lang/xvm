#pragma once

#include "../deps.h"
#include "../utils/index.h"
#include "../command_runner/index.h"

void run_command(const command_runner_t *runner);
void repl_command(const command_runner_t *runner);
void self_test_command(const command_runner_t *runner);
