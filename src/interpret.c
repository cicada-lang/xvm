#include "index.h"

void
interpret_token_list(vm_t *self, list_t *token_list) {
    program_t *program = program_create();
    token_t *token = list_start(token_list);
    while (token) {
        program_append_call(program, vm_word(self, token_string(token)));
        token = list_next(token_list);
    }

    vm_load_program(self, program);
}

void
interpret_code(vm_t *self, char *code) {
    lexer_t *lexer = lexer_create(code);
    lexer_lex(lexer);
    interpret_token_list(self, lexer_token_list(lexer));
    lexer_destroy(&lexer);
}
