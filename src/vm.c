#include "index.h"

struct _vm_t {
    dict_t *dict;
    value_stack_t *value_stack;
    return_stack_t *return_stack;
};

#define DICT_SIZE 1000003
#define VALUE_STACK_SIZE 10000
#define RETURN_STACK_SIZE 10000

vm_t *
vm_create(void) {
    vm_t *self = allocate(sizeof(vm_t));
    self->dict = dict_create(DICT_SIZE);
    self->value_stack = value_stack_create(VALUE_STACK_SIZE);
    self->return_stack = return_stack_create(RETURN_STACK_SIZE);
    return self;
}

void
vm_destroy(vm_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        vm_t *self = *self_ptr;
        dict_destroy(&self->dict);
        value_stack_destroy(&self->value_stack);
        return_stack_destroy(&self->return_stack);
        free(self);
        *self_ptr = NULL;
    }
}

word_t *
vm_word(vm_t *self, const char *name) {
    return dict_word(self->dict, name);
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

value_t
vm_value_stack_pop(vm_t *self) {
    return value_stack_pop(self->value_stack);
}

void
vm_value_stack_push(vm_t *self, value_t value) {
    value_stack_push(self->value_stack, value);
}

bool
vm_value_stack_is_empty(vm_t *self) {
    return value_stack_is_empty(self->value_stack);
}

frame_t *
vm_return_stack_pop(vm_t *self) {
    return return_stack_pop(self->return_stack);
}

void
vm_return_stack_push(vm_t *self, frame_t *frame) {
    return_stack_push(self->return_stack, frame);
}

bool
vm_return_stack_is_empty(vm_t *self) {
    return return_stack_is_empty(self->return_stack);
}

void
vm_load_token_list(vm_t *self, list_t *token_list) {
    program_t *program = program_create();
    token_t *token = list_start(token_list);
    while (token) {
        program_append_call(program, vm_word(self, token_string(token)));
        token = list_next(token_list);
    }

    vm_load(self, program);
}

void
vm_load_code(vm_t *self, char *code) {
    lexer_t *lexer = lexer_create(code);
    lexer_lex(lexer);
    vm_load_token_list(self, lexer_token_list(lexer));
    lexer_destroy(&lexer);
}

void
vm_load(vm_t *self, program_t *program) {
    frame_t *frame = frame_create(program);
    vm_return_stack_push(self, frame);
}

void
vm_step(vm_t *self) {
    frame_t *frame = vm_return_stack_pop(self);
    if (!frame) return;

    execute(self, frame);
}

void
vm_run(vm_t *self) {
    while(!vm_return_stack_is_empty(self)) {
        vm_step(self);
    }
}

void
vm_define_builtins(vm_t *self) {
    vm_define_primitive(self, "newline", _newline);

    vm_define_primitive(self, "int_print", _int_print);
    vm_define_primitive(self, "int_dup", _int_dup);
    vm_define_primitive(self, "int_mul", _int_mul);

    vm_define_primitive(self, "string_print", _string_print);
    vm_define_primitive(self, "string_append", _string_append);
    vm_define_primitive(self, "string_dup", _string_dup);
    vm_define_primitive(self, "string_length", _string_length);
}

vm_t *
vm_init(void) {
    vm_t *vm = vm_create();
    vm_define_builtins(vm);
    return vm;
}
