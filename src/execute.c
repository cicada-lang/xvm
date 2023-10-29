#include "index.h"

void
execute(xvm_t *vm, frame_t *frame) {
    instruction_t instruction = frame_fetch_instruction(frame);
    printf("instruction: %d\n", instruction);
    printf("vm: %p\n", (void *) vm);

    // execute_call(self, frame);
    // execute_value(self, frame);
    // execute_end(self, frame);
}
