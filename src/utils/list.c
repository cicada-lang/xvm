#include "index.h"

typedef struct _node_t node_t;

struct _node_t {
    node_t *next;
};

struct _list_t {
    size_t size;
};
