#include "everything.h"

int main(void) {
    env_t *env = env_new();
    printf("%ld\n", dict_size(env->dict));
    env_destroy(&env);
    return 0;
}
