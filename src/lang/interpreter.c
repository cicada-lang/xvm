#include "index.h"

struct _interpreter_t {
    const vm_t *vm;
    const char *code;
    lexer_t *lexer;
    list_t *program_list;
};

interpreter_t *
interpreter_create(const vm_t *vm, const char *code) {
    interpreter_t *self = allocate(sizeof(interpreter_t));
    self->vm = vm;
    self->code = code;
    self->lexer = lexer_create(code);
    lexer_lex(self->lexer);
    self->program_list = list_create();
    return self;
}

void
interpreter_destroy(interpreter_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        interpreter_t *self = *self_pointer;
        lexer_destroy(&self->lexer);
        // We use `NULL` as `item_free`, because there is
        // no need to free the programs in the list,
        // the number of which is very limited,
        // and they might be owned by the dict.
        list_destroy(&self->program_list, NULL);
        free(self);
        *self_pointer = NULL;
    }
}

static void interpreter_execute_token(interpreter_t *self, token_t *token);
static void interpreter_compile_token(interpreter_t *self, token_t *token, program_t *program);

void
interpreter_interpret(interpreter_t *self) {
    list_t *token_list = lexer_token_list(self->lexer);
    token_t *token = list_start(token_list);
    while (token) {
        program_t *program = list_last(self->program_list);
        if (program)
            interpreter_compile_token(self, token, program);
        else
            interpreter_execute_token(self, token);
        token = list_next(token_list);
    }
}

void
interpreter_execute_token(interpreter_t *self, token_t *token) {
    if (token_is_word(token)) {
        const char *string = token_string(token);
        if (string_is_int(string)) {
            vm_value_stack_push(self->vm, string_to_int(string));
        } else if (string_equal(string, "[")) {
            list_push(self->program_list, program_create());
        } else if (string_equal(string, "]")) {
            assert(false && "[interpreter_execute_token] I meet extract ]");
        } else if (string_starts_with(string, "'")) {
            vm_value_stack_push(self->vm, (value_t) vm_word(self->vm, string + 1));
        } else {
            vm_run_word(self->vm, vm_word(self->vm, string));
        }
    } else if (token_is_double_quotes(token)) {
        vm_value_stack_push(self->vm, (value_t) string_clone(token_string(token)));
    } else {
        printf(
            "[interpreter_execute_token] I meet unknown token: %s",
            token_string(token));
        assert(false);
    }
}

void
interpreter_compile_token(interpreter_t *self, token_t *token, program_t *program) {
    if (token_is_word(token)) {
        const char *string = token_string(token);
        if (string_is_int(string)) {
            program_append_literal_int(program, string_to_int(string));
        } else if (string_equal(string, "[")) {
            list_push(self->program_list, program_create());
        } else if (string_equal(string, "]")) {
            list_pop(self->program_list);
            if (list_is_empty(self->program_list)) {
                vm_value_stack_push(self->vm, (value_t) program);
            } else {
                program_append_literal_program(list_last(self->program_list), program);
            }
        } else if (string_starts_with(string, "'")) {
            program_append_literal_word(program, vm_word(self->vm, string + 1));
        } else {
            program_append_call(program, vm_word(self->vm, string));
        }
    } else if (token_is_double_quotes(token)) {
        program_append_literal_string(program, string_clone(token_string(token)));
    } else {
        printf(
            "[interpreter_compile_token] I meet unknown token: %s",
            token_string(token));
        assert(false);
    }
}
