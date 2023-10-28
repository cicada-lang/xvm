#pragma once

// typedef struct _xvm_t xvm_t;

// struct _xvm_t {
//     dict_t *dict;
// };

typedef struct {
    dict_t *dict;
} xvm_t;

xvm_t *xvm_new(void);
void xvm_destroy(xvm_t **self_p);
