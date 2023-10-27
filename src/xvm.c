#include "everything.h"

void xvm_define_program(const char *name, const char *body[]);

int main(void) {
    dict_t *dict = dict_new(10);
    printf("%ld\n", dict_size(dict));

    xvm_define_program("square", (const char *[]){
            "dup",
            "mul",
        });

    return 0;
}

void xvm_define_program(const char *name, const char *body[]) {
    printf("%s\n", name);
    printf("%s\n", body[0]);
    printf("%s\n", body[1]);
    // printf("%s\n", body[2]);
}
