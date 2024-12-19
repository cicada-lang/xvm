#pragma once

tag_t value_tag(value_t value);

value_t atom_value(size_t atom);

value_t value_encode_8_bit(uint8_t target);
uint8_t value_decode_8_bit(value_t value);
