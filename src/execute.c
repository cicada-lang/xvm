#include "index.h"

void
execute(xvm_t *vm, frame_t *frame) {
    if (frame_is_end(frame)) return;

    instruction_t instruction = frame_fetch_instruction(frame);
    if (instruction == CALL) {
        execute_call(vm, frame);
        return;
    } else if (instruction == VALUE) {
        execute_value(vm, frame);
        return;
    } else {
        assert(false);
    }
}

void
execute_call(xvm_t *vm, frame_t *frame) {
    word_t *word = frame_fetch_word(frame);
    xvm_return_stack_push(vm, frame);

    primitive_t *primitive = word_primitive(word);
    if (primitive) {
        (*primitive)(vm);
        return;
    }

    program_t *program = word_program(word);
    frame_t *new_frame = frame_create(program);
    xvm_return_stack_push(vm, new_frame);
}

void
execute_value(xvm_t *vm, frame_t *frame) {
    value_t value = frame_fetch_value(frame);
    xvm_return_stack_push(vm, frame);
    xvm_value_stack_push(vm, value);
}
