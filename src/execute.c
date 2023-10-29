#include "index.h"

void
execute(xvm_t *vm, frame_t *frame) {
    if (frame_is_end(frame)) return;

    instruction_t instruction = frame_fetch_instruction(frame);
    if (instruction == CALL) {
        execute_call(vm, frame);
        return;
    } else if (instruction == VALUE) {
        // execute_value(vm, frame);
        // return;
    } else {
        // assert(false);
    }
}

void
execute_call(xvm_t *vm, frame_t *frame) {
    xvm_return_stack_push(vm, frame);
    word_t *word = frame_fetch_word(frame);
    program_t *program = word_program(word);
    frame_t *new_frame = frame_create(program);
    xvm_return_stack_push(vm, new_frame);
}
