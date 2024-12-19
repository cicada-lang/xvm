#include "index.h"

value_t
xaddress(void *address) {
    assert(address_is_8_bytes_aligned(address));
    return (void *) (((uint64_t) address) | XADDRESS);
}

bool
value_is_xaddress(value_t value) {
    return value_tag(value) == XADDRESS;
}

void*
value_to_address(value_t value) {
    assert(value_is_xaddress(value));
    return (void *) (((uint64_t) value) & 0xfffffffffffffff8);
}
