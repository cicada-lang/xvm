#include "index.h"

void
interpret_token(vm_t *vm, token_t *token) {
    (void) vm;
    (void) token;
    // program_append_call(program, vm_word(vm, token_string(token)));

    // vm_load_program(vm, program);
}

void
interpret_code(vm_t *vm, char *code) {
    lexer_t *lexer = lexer_create(code);
    lexer_lex(lexer);
    list_t *token_list = lexer_token_list(lexer);
    token_t *token = list_start(token_list);
    while (token) {
        interpret_token(vm, token);
        token = list_next(token_list);
    }

    lexer_destroy(&lexer);
}
