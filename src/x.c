#include "command_runner/index.h"
#include "commands/index.h"
#include "lang/index.h"

int
main(int argc, const char *argv[]) {
    command_runner_t *runner = command_runner_create(
        "x-script", X_VERSION, argc, argv);

    command_runner_mount(runner, help_command);
    command_runner_mount(runner, run_command);
    command_runner_mount(runner, repl_command);
    command_runner_mount(runner, version_command);
    command_runner_mount(runner, self_test_command);

    int status_code = command_runner_run(runner);
    command_runner_destroy(&runner);
    return status_code;
}
