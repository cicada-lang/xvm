#pragma once

value_t xaddress(size_t address);

bool value_is_xaddress(value_t value);
size_t value_to_address(value_t value);