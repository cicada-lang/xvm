#include "everything.h"

int main(void) {
    dict_t *dict = dict_new(10);
    printf("%ld\n", dict_size(dict));
    return 0;
}
