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
