#include "index.h"

value_t
xaddress(size_t address) {
    return (void *) ((address << 3) | XADDRESS);
}

bool
value_is_xaddress(value_t value) {
    return value_tag(value) == XADDRESS;
}

size_t
value_to_address(value_t value) {
    assert(value_is_xaddress(value));
    return ((uint64_t) value) >> 3;
}
