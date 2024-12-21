#include "index.h"

value_t
xtrue(void) {
    return (value_t) 0x00ffffffffffffff;
}

value_t
xfalse(void) {
    return (value_t) 0x01ffffffffffffff;
}

value_t
xbool(bool target) {
    return target ? xtrue() : xfalse();
}

bool
value_is_xbool(value_t value) {
    return value == xtrue() || value == xfalse();
}

bool
value_to_bool(value_t value) {
    assert(value_is_xbool(value));
    return value == xtrue();
}


value_t
xbool_and(value_t x, value_t y) {
    return xbool(value_to_bool(x) && value_to_bool(y));
}

value_t
xbool_or(value_t x, value_t y) {
    return xbool(value_to_bool(x) || value_to_bool(y));
}

value_t xbool_not(value_t x) {
    return xbool(!value_to_bool(x));
}
