#pragma once

// double linked list, with a private cursor.

list_t *list_create(void);
void list_destroy(list_t **self_ptr, list_item_delete_fn_t *delete_fn);
void list_purge(list_t *self, list_item_delete_fn_t *delete_fn);

size_t list_lenght(list_t *self);
bool list_has(list_t *self, void *item);
bool list_remove(list_t *self, void *item);

void *list_current(list_t *self);
void *list_first(list_t *self);
void *list_last(list_t *self);

// move the cursor.

void *list_start(list_t *self);
void *list_next(list_t *self);
void *list_prev(list_t *self);
void *list_end(list_t *self);

// at the end of the list.

void list_push(list_t *self, void *item);
void *list_pop(list_t *self);

// at the start of the list.

void list_unshift(list_t *self, void *item);
void *list_shift(list_t *self);

void list_test(void);
