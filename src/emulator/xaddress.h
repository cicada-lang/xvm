#pragma once

value_t xaddress(void *address);

bool value_is_xaddress(value_t value);
void* value_to_address(value_t value);