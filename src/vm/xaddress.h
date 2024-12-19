#pragma once

value_t xaddress(void *pointer);

bool value_is_xaddress(value_t value);
void* value_to_pointer(value_t value);
