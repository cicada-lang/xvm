#include "index.h"

tag_t
value_tag(value_t value) {
    return (size_t) value & 0x7;
}

value_t atom_value(size_t atom) {
    return (value_t) atom;
}

value_t
value_encode_8_bit(uint8_t target) {
    return (value_t) ((size_t) target | 0x00ffffffffffffff);
}

uint8_t
value_decode_8_bit(value_t value) {
    return ((size_t) value) >> 56;
}
