#include "index.h"

struct _vm_t {
    dict_t *dict;
    value_stack_t *value_stack;
    value_stack_t *input_type_stack;
    return_stack_t *return_stack;
};

#define DICT_SIZE 1000003
#define INPUT_TYPE_STACK_SIZE 1000
#define VALUE_STACK_SIZE 10000
#define RETURN_STACK_SIZE 10000

vm_t *
vm_create(void) {
    vm_t *self = allocate(sizeof(vm_t));
    self->dict = dict_create(DICT_SIZE);
    self->value_stack = value_stack_create(VALUE_STACK_SIZE);
    self->input_type_stack = value_stack_create(INPUT_TYPE_STACK_SIZE);
    self->return_stack = return_stack_create(RETURN_STACK_SIZE);
    return self;
}

void
vm_destroy(vm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        vm_t *self = *self_pointer;
        dict_destroy(&self->dict);
        value_stack_destroy(&self->value_stack);
        value_stack_destroy(&self->input_type_stack);
        return_stack_destroy(&self->return_stack);
        free(self);
        *self_pointer = NULL;
    }
}

word_t *
vm_word(const vm_t *self, const char *name) {
    return dict_word(self->dict, name);
}

value_t
vm_value_stack_pop(const vm_t *self) {
    return value_stack_pop(self->value_stack);
}

void
vm_value_stack_push(const vm_t *self, value_t value) {
    value_stack_push(self->value_stack, value);
}

bool
vm_value_stack_is_empty(const vm_t *self) {
    return value_stack_is_empty(self->value_stack);
}

value_t
vm_input_type_stack_pop(const vm_t *self) {
    return value_stack_pop(self->input_type_stack);
}

void
vm_input_type_stack_push(const vm_t *self, value_t value) {
    value_stack_push(self->input_type_stack, value);
}

bool
vm_input_type_stack_is_empty(const vm_t *self) {
    return value_stack_is_empty(self->input_type_stack);
}

frame_t *
vm_return_stack_pop(const vm_t *self) {
    return return_stack_pop(self->return_stack);
}

void
vm_return_stack_push(const vm_t *self, frame_t *frame) {
    return_stack_push(self->return_stack, frame);
}

bool
vm_return_stack_is_empty(const vm_t *self) {
    return return_stack_is_empty(self->return_stack);
}

frame_t *
vm_return_stack_tos(const vm_t *self) {
    // This function normalize the top frame,
    // proper tail call is implemented by
    // calling this function before pushing `return_stack`.

    while (!vm_return_stack_is_empty(self)) {
        frame_t *frame = vm_return_stack_pop(self);
        if (frame_is_end(frame)) {
            frame_destroy(&frame);
        } else {
            vm_return_stack_push(self, frame);
            return frame;
        }
    }

    return NULL;
}

void
vm_load_program(const vm_t *self, program_t *program) {
    vm_return_stack_tos(self);

    frame_t *frame = frame_create(program);
    vm_return_stack_push(self, frame);
}

void
vm_step(const vm_t *self) {
    frame_t *frame = vm_return_stack_tos(self);
    if (!frame) return;

    opcode_t opcode = frame_fetch_opcode(frame);
    execute(self, frame, opcode);
}

void
vm_run(const vm_t *self) {
    while(!vm_return_stack_is_empty(self)) {
        vm_step(self);
    }
}

void
vm_run_word(const vm_t *self, word_t *word) {
    program_t *program = program_create();
    program_append_call(program, word);
    vm_load_program(self, program);
    vm_run(self);
    program_destroy(&program);
}

program_t *
vm_build_program(vm_t *self, const char *name) {
    word_t *word = vm_word(self, name);
    program_t *found = word_program(word);
    if (found) return found;

    program_t *program = program_create();
    word_program_set(word, program);
    return program;
}

void
vm_define_primitive(vm_t *self, const char *name, primitive_t *primitive) {
    word_t *word = vm_word(self, name);
    word_primitive_set(word, primitive);
}

vm_t *
vm_init(void) {
    vm_t *vm = vm_create();
    define_all_builtins(vm);
    return vm;
}

void
vm_interpret_code(vm_t *self, const char *code) {
    interpreter_t *interpreter = interpreter_create(self, code);
    interpreter_interpret(interpreter);
    interpreter_destroy(&interpreter);
}
