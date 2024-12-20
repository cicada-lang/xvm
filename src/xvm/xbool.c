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
