#include "index.h"

struct _lexer_t {
    char *code;
    list_t *token_list;
};

lexer_t *lexer_create(char *code) {
    lexer_t *self = allocate(sizeof(lexer_t));
    self->code = code;
    self->token_list = list_create();
    return self;
}

void
lexer_destroy(lexer_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        lexer_t *self = *self_ptr;
        free(self->code);
        list_destroy(&self->token_list, (list_item_free_fn_t *) token_free);
        free(self);
        *self_ptr = NULL;
    }
}

token_t **
lexer_tokens(lexer_t *self) {
    token_t **tokens = allocate_array(
        list_lenght(self->token_list),
        sizeof(token_t *));
    size_t index = 0;
    token_t *token = list_start(self->token_list);
    while (token) {
        tokens[index] = token;
        token = list_next(self->token_list);
        index++;
    }

    return tokens;
}
