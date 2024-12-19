#include "index.h"

value_t
xtrue(void) {
    return (value_t) 0x00ffffffffffffff;
}

value_t
xfalse(void) {
    return (value_t) 0x01ffffffffffffff;
}

bool
is_xbool(value_t value) {
    return value == xtrue() || value == xfalse();
}

value_t
as_xbool(value_t value) {
    assert(is_xbool(value));
    return value;
}
