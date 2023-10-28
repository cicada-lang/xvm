#include "everything.h"

int main(void) {
    xvm_t *xvm = xvm_new();
    printf("%ld\n", dict_size(xvm->dict));
    xvm_destroy(&xvm);
    printf("%d\n", XVM_VERSION);
    return 0;
}
