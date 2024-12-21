#include "index.h"

// double-precision floating-point but truncate the lower 3 bits

value_t
xfloat(double target) {
    return (value_t) (((uint64_t) target) | XFLOAT);
}

bool
is_xfloat(value_t value) {
    return value_tag(value) == XFLOAT;
}
