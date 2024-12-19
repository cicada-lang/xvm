#include "index.h"

value_t
xaddress(void *pointer) {
    assert(pointer_is_8_bytes_aligned(pointer));
    return (void *) (((uint64_t) pointer) | XADDRESS);
}

bool
value_is_xaddress(value_t value) {
    return value_tag(value) == XADDRESS;
}

void*
value_to_pointer(value_t value) {
    assert(value_is_xaddress(value));
    return (void *) (((uint64_t) value) & 0xfffffffffffffff8);
}
