#include "everything.h"

int main(void) {
    dict_t *dict = dict_new(10);
    puts("Hello, World");
    printf("%ld", dict_size(dict));
    return 0;
}
