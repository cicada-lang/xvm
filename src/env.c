#include "everything.h"

#define DICT_SIZE 1000000

env_t *env_new(void) {
    env_t *self = (env_t *) calloc(1, sizeof(env_t));
    self->dict = dict_new(DICT_SIZE);
    return self;
}

void env_destroy(env_t **self_p) {
    assert (self_p);
    if (*self_p) {
        env_t *self = *self_p;
        dict_destroy(&self->dict);
        free(self);
        *self_p = NULL;
    }
}
