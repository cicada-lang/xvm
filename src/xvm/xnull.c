#include "index.h"

value_t
xnull(void) {
    return (value_t) 0xffffffffffffffff;
}

bool
value_is_xnull(value_t value) {
    return value == xnull();
}

void *
value_to_null(value_t value) {
    assert(value_is_xnull(value));
    return NULL;
}
