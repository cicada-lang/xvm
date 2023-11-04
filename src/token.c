#include "index.h"

typedef enum {
    WORD_TOKEN,
    STRING_TOKEN,
} token_kind_t;

struct _token_t {
    token_kind_t kind;
    char *string;
    size_t start;
    size_t end;
};
