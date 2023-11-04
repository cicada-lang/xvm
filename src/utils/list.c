#include "index.h"

typedef struct _node_t node_t;

struct _node_t {
    node_t *next;
};

struct _list_t {
    size_t size;
};

list_t *
list_create(void) {
    list_t *self = (list_t *) calloc(1, sizeof(list_t));
    return self;
}
