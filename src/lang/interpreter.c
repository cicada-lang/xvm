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
    if (token_is_word(token)) {
        char *string = string_dup(token_string(token));
        if (string_is_int(string))
            vm_value_stack_push(self->vm, string_to_int(string));
        else
            vm_run_word(self->vm, vm_word(self->vm, string));
    } else if (token_is_double_quotes(token)) {
        char *string = string_dup(token_string(token));
        vm_value_stack_push(self->vm, (value_t) string);
    } else {
        printf(
            "[interpreter_interpret_token] I meet unknown token: %s",
            token_string(token));
        assert(false);
    }
}
