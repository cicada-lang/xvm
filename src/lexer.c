#include "index.h"

struct _lexer_t {
    char *code;
};

lexer_t *lexer_create(void) {
    lexer_t *self = (lexer_t *) calloc(1, sizeof(lexer_t));
    return self;
}
