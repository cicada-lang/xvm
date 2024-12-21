#pragma once

value_t xtrue(void);
value_t xfalse(void);
value_t xbool(bool target);

bool value_is_xbool(value_t value);
bool value_to_bool(value_t value);

value_t xbool_and(value_t x, value_t y);
value_t xbool_or(value_t x, value_t y);
value_t xbool_not(value_t x);
