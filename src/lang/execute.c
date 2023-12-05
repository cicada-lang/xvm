#include "index.h"

static void execute_call(const vm_t *self, frame_t *frame);

void
execute(const vm_t *vm, frame_t *frame, opcode_t opcode) {
    switch (opcode) {

    case CALL: {
        execute_call(vm, frame);
        return;
    }

    case  LITERAL_INT:
    case  LITERAL_WORD:
    case  LITERAL_BOOLEAN:
    case  LITERAL_NULL:
    case  LITERAL_FLOAT: {
        vm_value_stack_push(vm, frame_fetch_value(frame));
        return;
    }

    case LITERAL_STRING: {
        char *string = (char *) frame_fetch_value(frame);
        vm_value_stack_push(vm, (value_t) string_dup(string));
        return;
    }

    case LITERAL_PROGRAM: {
        // No need to dup `program`, because
        // we currently do not generate program dynamicly.
        // -- there is no function such as `program_append`.
        program_t *program = (program_t *) frame_fetch_value(frame);
        vm_value_stack_push(vm, (value_t) program);
        return;
    }

    default: {
        printf("[execute] unknown opcode: %d\n", opcode);
        assert(false && "[execute] unknown opcode.");
        return;
    }
    }
}

void
proper_tail_call(const vm_t *vm, frame_t *frame) {
    if (frame_is_end(frame)) {
        vm_return_stack_pop(vm);
        frame_destroy(&frame);
    }
}

void
execute_call(const vm_t *vm, frame_t *frame) {
    word_t *word = frame_fetch_word(frame);

    primitive_t *primitive = word_primitive(word);
    if (primitive) {
        (*primitive)(vm);
        // proper_tail_call(vm, frame);
        return;
    }

    program_t *program = word_program(word);
    if (program) {
        proper_tail_call(vm, frame);
        frame_t *new_frame = frame_create(program);
        vm_return_stack_push(vm, new_frame);
        return;
    }

    printf("[execute_call] word name: %s\n", word_name(word));
    assert(false && "[execute_call] undefined word name.");
}
