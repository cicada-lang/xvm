#include "index.h"

bool
value_is_xopcode(value_t value) {
    return (((uint64_t) value) & 0x0000ffffffffffff) == 0x0000ffffffffffff;
}

value_t
xopcode_end(void) {
    return (value_t) 0x0000ffffffffffff;
}

value_t
xopcode_call(void) {
    return (value_t) 0x0001ffffffffffff;
}
