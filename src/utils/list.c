#include "index.h"

typedef struct _node_t node_t;

struct _node_t {
    node_t *prev;
    node_t *next;
    void *item;
};

struct _list_t {
    node_t *first;
    node_t *last;
    node_t *cursor;
    size_t size;
};

list_t *
list_create(void) {
    list_t *self = (list_t *) calloc(1, sizeof(list_t));
    return self;
}

void
list_destroy(list_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        list_t *self = *self_ptr;
        // list_purge(self);
        free(self);
        *self_ptr = NULL;
    }
}

void *
list_current(list_t *self) {
    assert(self);
    if (self->cursor)
        return self->cursor->item;
    else
        return NULL;
}

void *list_first(list_t *self) {
    assert(self);
    return self->first->item;
}

void *list_last(list_t *self) {
    assert(self);
    return self->last->item;
}

void *
list_start(list_t *self) {
    assert(self);
    self->cursor = self->first;
    return list_current(self);
}

void *
list_next(list_t *self) {
    assert(self);
    self->cursor = self->cursor
        ? self->cursor->next
        : self->first;
    return list_current(self);
}

void *
list_end(list_t *self)
{
    assert(self);
    self->cursor = self->last;
    return list_current(self);
}
