#include "index.h"

// int64_t but truncate the lower 3 bits

value_t
xint(int64_t target) {
    return (value_t) ((target << 3) | XINT);
}

bool
is_xint(value_t value) {
    return value_tag(value) == XINT;
}

int64_t
to_xint(value_t value) {
    assert(is_xint(value));
    return ((int64_t) value) >> 3;
}
