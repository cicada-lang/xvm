#include "index.h"

// The interpreter does not own `vm`.

struct _interpreter_t {
    vm_t *vm;
    const char *code;
    lexer_t *lexer;
};

interpreter_t *
interpreter_create(vm_t *vm, const char *code) {
    interpreter_t *self = allocate(sizeof(interpreter_t));
    self->vm = vm;
    self->code = code;
    self->lexer = lexer_create(code);
    lexer_lex(self->lexer);
    return self;
}

void
interpreter_destroy(interpreter_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        interpreter_t *self = *self_ptr;
        lexer_destroy(&self->lexer);
        free(self);
        *self_ptr = NULL;
    }
}

void interpreter_interpret_token(interpreter_t *self, token_t *token);

void
interpreter_interpret(interpreter_t *self) {
    list_t *token_list = lexer_token_list(self->lexer);
    token_t *token = list_start(token_list);
    while (token) {
        interpreter_interpret_token(self, token);
        token = list_next(token_list);
    }
}

void
interpreter_interpret_token(interpreter_t *self, token_t *token) {
    if (token_word_p(token)) {
        program_t *program = program_create();
        program_append_call(program, vm_word(self->vm, token_string(token)));
        vm_load_program(self->vm, program);
        vm_run(self->vm);
        program_destroy(&program);
    }
}
