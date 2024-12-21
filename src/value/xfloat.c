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

double
to_double(value_t value) {
    assert(is_xfloat(value));
    return (double) (((uint64_t) value) & (0xffffffffffffff07));
}

value_t
xfloat_add(value_t x, value_t y) {
    return xint(to_int64(x) + to_int64(y));
}

value_t
xfloat_sub(value_t x, value_t y) {
    return xfloat(to_double(x) - to_double(y));
}

value_t
xfloat_mul(value_t x, value_t y) {
    return xfloat(to_double(x) * to_double(y));
}

value_t
xfloat_div(value_t x, value_t y) {
    return xfloat(to_double(x) / to_double(y));
}

value_t
xfloat_mod(value_t x, value_t y) {
    return xfloat(fmod(to_double(x), to_double(y)));
}
