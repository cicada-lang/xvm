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

static void execute_word(const vm_t *vm, word_t *word);

void
execute_call(const vm_t *vm, frame_t *frame) {
    word_t *word = frame_fetch_word(frame);
    vm_return_stack_push(vm, frame);

    execute_word(vm, word);
}

void
execute_word(const vm_t *vm, word_t *word) {
    type_constructor_t *type_constructor = word_type_constructor(word);
    if (type_constructor) {
        size_t arity = type_constructor_arity(type_constructor);
        type_t *type = type_term_create(word_name(word), arity);
        for (size_t i = 0; i < arity; i++) {
            type_t *type_arg = (type_t *) vm_value_stack_pop(vm);
            type_term_type_arg_set(type, arity - 1 - i, type_arg);
        }

        vm_value_stack_push(vm, (value_t) type);
        return;
    }

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

    printf("[execute_word] word name: %s\n", word_name(word));
    assert(false && "[execute_word] undefined word name.");
}
