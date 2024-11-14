#include "commander/index.h"
#include "commands/index.h"
#include "lang/index.h"

int
main(int argc, char *argv[]) {
    commander_t *runner = commander_new(
        "xvm", X_VERSION, argc, argv);

    commander_mount(runner, run_command);
    commander_mount(runner, repl_command);
    commander_mount(runner, self_test_command);
    commander_mount(runner, default_help_command);
    commander_mount(runner, default_version_command);

    int status_code = commander_run(runner);
    commander_destroy(&runner);
    return status_code;
}
