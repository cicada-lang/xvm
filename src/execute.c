#include "index.h"

void
execute(xvm_t *vm, frame_t *frame) {
    instruction_t instruction = frame_fetch_instruction(frame);
    // if (instruction == CALL)
    //     return execute_call(self, frame);
    // else if (instruction == VALUE)
    //     return execute_value(self, frame);
    // else
    //     assert(false);

    printf("instruction: %d\n", instruction);
    printf("vm: %p\n", (void *) vm);
}
