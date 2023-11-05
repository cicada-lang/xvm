#include "index.h"

void
interpret_token_list(vm_t *vm, list_t *token_list) {
    program_t *program = program_create();
    token_t *token = list_start(token_list);
    while (token) {
        program_append_call(program, vm_word(vm, token_string(token)));
        token = list_next(token_list);
    }

    vm_load_program(vm, program);
}

void
interpret_code(vm_t *vm, char *code) {
    lexer_t *lexer = lexer_create(code);
    lexer_lex(lexer);
    interpret_token_list(vm, lexer_token_list(lexer));
    lexer_destroy(&lexer);
}
