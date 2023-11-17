#include "index.h"

static void execute_call(const vm_t *self, frame_t *frame);

void
execute(const vm_t *vm, frame_t *frame) {
    if (frame_is_end(frame)) {
        frame_destroy(&frame);
        return;
    }

    opcode_t opcode = frame_fetch_opcode(frame);
    if (opcode == CALL) {
        execute_call(vm, frame);
        return;
    } else if (
        opcode == LITERAL_INT       ||
        opcode == LITERAL_WORD      ||
        opcode == LITERAL_BOOLEAN   ||
        opcode == LITERAL_NULL      ||
        opcode == LITERAL_FLOAT
        ) {
        vm_value_stack_push(vm, frame_fetch_value(frame));
        vm_return_stack_push(vm, frame);
        return;
    } else if (opcode == LITERAL_STRING) {
        char *string = (char *) frame_fetch_value(frame);
        vm_value_stack_push(vm, (value_t) string_dup(string));
        vm_return_stack_push(vm, frame);
    } else if (opcode == LITERAL_PROGRAM) {
        // No need to dup `program`, because
        // we currently do not generate program dynamicly.
        // -- there is no function such as `program_append`.
        program_t *program = (program_t *) frame_fetch_value(frame);
        vm_value_stack_push(vm, (value_t) program);
        vm_return_stack_push(vm, frame);
    } else {
        printf("[execute] unknown opcode: %d\n", opcode);
        assert(false && "[execute] unknown opcode.");
    }
}

void
execute_call(const vm_t *vm, frame_t *frame) {
    word_t *word = frame_fetch_word(frame);
    vm_return_stack_push(vm, frame);

    primitive_t *primitive = word_primitive(word);
    if (primitive) {
        (*primitive)(vm);
        return;
    }

    program_t *program = word_program(word);
    if (program) {
        frame_t *new_frame = frame_create(program);
        vm_return_stack_push(vm, new_frame);
        return;
    }

    printf("[execute_call] word name: %s\n", word_name(word));
    assert(false && "[execute_call] undefined word name.");
}
