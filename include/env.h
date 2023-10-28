#pragma once

// typedef struct _env_t env_t;

// struct _env_t {
//     dict_t *dict;
// };

typedef struct {
    dict_t *dict;
} env_t;

env_t *env_new(void);
void env_destroy(env_t **self_p);
