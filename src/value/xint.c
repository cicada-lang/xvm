#include "index.h"

// int64_t but truncate the lower 3 bits

value_t
xint(int64_t target) {
    return (value_t) ((target << 3) | XINT);
}
