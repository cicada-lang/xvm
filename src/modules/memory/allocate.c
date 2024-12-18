#include "index.h"

// The address of a block returned by malloc or realloc in GNU systems
// is always a multiple of eight (or sixteen on 64-bit systems).
// -- https://www.gnu.org/software/libc/manual/html_node/Aligned-Memory-Blocks.html

static bool
is_8_bytes_aligned(void *address) {
    return (((uintptr_t) address) & ((uintptr_t) 0x7)) == 0;
}

void *
allocate(size_t size) {
    void *address = calloc(1, size);
    assert(address);
    assert(is_8_bytes_aligned(address));
    return address;
}

void *
allocate_many(size_t size, size_t unit_size) {
    void *address = calloc(size, unit_size);
    assert(address);
    assert(is_8_bytes_aligned(address));
    return address;
}

void *
allocate_pointers(size_t size) {
    return allocate_many(size, sizeof(void *));
}
