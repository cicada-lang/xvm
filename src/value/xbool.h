#pragma once

value_t xtrue(void);
value_t xfalse(void);
value_t xbool(bool target);

bool value_is_xbool(value_t value);
bool value_to_bool(value_t value);
