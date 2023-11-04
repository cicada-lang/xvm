#include "index.h"

typedef enum {
    WORD_TOKEN,
    STRING_TOKEN,
} token_kind_t;

struct _token_t {
    token_kind_t kind;
    char *string;
};


token_t **
token_lex(char *code) {
    (void) code;
    return NULL;
}
