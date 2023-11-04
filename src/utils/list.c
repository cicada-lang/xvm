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

void *
list_first(list_t *self) {
    assert(self);
    return self->first->item;
}

void *
list_last(list_t *self) {
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
list_end(list_t *self) {
    assert(self);
    self->cursor = self->last;
    return list_current(self);
}

void
list_push(list_t *self, void *item) {
    node_t *node = (node_t *) calloc(1, sizeof (node_t));
    assert(node);
    node->item = item;

    if (self->last) {
        self->last->next = node;
        node->prev = self->last;
        node->next = NULL;
    } else {
        self->first = node;
        node->prev = NULL;
        node->next = NULL;
    }

    self->last = node;
    self->size++;
}

void *
list_pop(list_t *self) {
    if (self->cursor == self->last)
        self->cursor = NULL;

    node_t *node = self->last;
    if (!node) return NULL;

    if (self->first == node)
        self->first = NULL;

    void *item = node->item;

    if (node->prev) {
        self->last = node->prev;
        self->last->next = NULL;
    } else {
        self->last = NULL;
    }

    free(node);
    self->size--;

    return item;
}

void
list_unshift(list_t *self, void *item) {
    node_t *node = (node_t *) calloc(1, sizeof (node_t));
    assert(node);
    node->item = item;

    if (self->first) {
        self->first->prev = node;
        node->next = self->first;
        node->prev = NULL;
    } else {
        self->last = node;
        node->next = NULL;
        node->prev = NULL;
    }

    self->first = node;
    self->size++;
}

void *
list_shift(list_t *self) {
    if (self->cursor == self->first)
        self->cursor = NULL;

    node_t *node = self->first;
    if (!node) return NULL;

    if (self->last == node)
        self->last = NULL;

    void *item = node->item;

    if (node->next) {
        self->first = node->next;
        self->first->prev = NULL;
    } else {
        self->first = NULL;
    }

    free(node);
    self->size--;

    return item;
}

void
list_test(void) {
    printf("<list>");

    list_t *list = list_create();
    assert(list);
    // assert(list_lenght(list) == 0);

    //  Three items we'll use as test data
    //  List items are void *, not particularly strings
    char *cheese = string_dup("boursin");
    char *bread = string_dup("baguette");
    char *wine = string_dup("bordeaux");

    list_push(list, cheese);
    // assert(list_lenght(list) == 1);
    // assert(list_has(list, cheese));
    // assert(!list_has(list, bread));
    // assert(!list_has(list, wine));
    list_push(list, bread);
    // assert(list_lenght(list) == 2);
    // assert(list_has(list, cheese));
    // assert(list_has(list, bread));
    // assert(!list_has(list, wine));
    list_push(list, wine);
    // assert(list_lenght(list) == 3);
    // assert(list_has(list, cheese));
    // assert(list_has(list, bread));
    // assert(list_has(list, wine));

    assert(list_first(list) == cheese);
    assert(list_next(list) == cheese);

    assert(list_start(list) == cheese);
    assert(list_last(list) == wine);
    assert(list_next(list) == bread);

    // assert(list_first(list) == cheese);
    // assert(list_next(list) == bread);
    // assert(list_next(list) == wine);
    // assert(list_next(list) == NULL);
    // //  After we reach end of list, next wraps around
    // assert(list_next(list) == cheese);
    // assert(list_lenght(list) == 3);

    // list_remove(list, wine);
    // assert(list_lenght(list) == 2);

    // assert(list_first(list) == cheese);
    // list_remove(list, cheese);
    // assert(list_lenght(list) == 1);
    // assert(list_first(list) == bread);

    // list_remove(list, bread);
    // assert(list_lenght(list) == 0);

    // list_append(list, cheese);
    // list_append(list, bread);
    // assert(list_last(list) == bread);
    // list_remove(list, bread);
    // assert(list_last(list) == cheese);
    // list_remove(list, cheese);
    // assert(list_last(list) == NULL);

    // list_push(list, cheese);
    // assert(list_lenght(list) == 1);
    // assert(list_first(list) == cheese);

    // list_push(list, bread);
    // assert(list_lenght(list) == 2);
    // assert(list_first(list) == bread);
    // assert(list_item(list) == bread);

    // list_append(list, wine);
    // assert(list_lenght(list) == 3);
    // assert(list_first(list) == bread);

    // list_t *sub_list = list_dup(list);
    // assert(sub_list);
    // assert(list_lenght(sub_list) == 3);

    // list_sort(list, NULL);
    // char *item;
    // item = (char *) list_pop(list);
    // assert(item == bread);
    // item = (char *) list_pop(list);
    // assert(item == wine);
    // item = (char *) list_pop(list);
    // assert(item == cheese);
    // assert(list_lenght(list) == 0);

    // assert(list_lenght(sub_list) == 3);
    // list_push(list, sub_list);
    // list_t *sub_list_2 = list_dup(sub_list);
    // list_append(list, sub_list_2);
    // assert(list_freefn(list, sub_list, &s_list_free, false) == sub_list);
    // assert(list_freefn(list, sub_list_2, &s_list_free, true) == sub_list_2);
    // list_destroy(&list);

    // //  Test autofree functionality
    // list = list_new();
    // assert(list);
    // list_autofree(list);
    // //  Set equals function otherwise equals will not work as autofree copies strings
    // list_comparefn(list,(list_compare_fn *) strcmp);
    // list_push(list, bread);
    // list_append(list, cheese);
    // assert(list_lenght(list) == 2);
    // list_append(list, wine);
    // assert(list_has(list, wine));
    // list_remove(list, wine);
    // assert(!list_has(list, wine));
    // assert(streq((const char *) list_first(list), bread));
    // item = (char *) list_pop(list);
    // assert(streq(item, bread));
    // free(item);
    // item = (char *) list_pop(list);
    // assert(streq(item, cheese));
    // free(item);

    list_destroy(&list);
    assert(list == NULL);

    printf("</list>\n");
}
