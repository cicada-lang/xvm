#pragma once

list_t *list_create(void);
void list_destroy(list_t **self_ptr);

//  Return the item at the head of list. If the list is empty, returns NULL.
//  Leaves cursor pointing at the head item, or NULL if the list is empty.
void *list_first(list_t *self);

//  Return the next item. If the list is empty, returns NULL. To move to
//  the start of the list call list_first(). Advances the cursor.
void *list_next(list_t *self);

// //  Return the item at the tail of list. If the list is empty, returns NULL.
// //  Leaves cursor pointing at the tail item, or NULL if the list is empty.
// void *list_last(list_t *self);

// //  Return first item in the list, or null, leaves the cursor
// void *list_head(list_t *self);

// //  Return last item in the list, or null, leaves the cursor
// void *list_tail(list_t *self);

// //  Return the current item of list. If the list is empty, returns NULL.
// //  Leaves cursor pointing at the current item, or NULL if the list is empty.
// void *list_item(list_t *self);

// //  Append an item to the end of the list, return 0 if OK or -1 if this
// //  failed for some reason(invalid input). Note that if a duplicator has
// //  been set, this method will also duplicate the item.
// int list_append(list_t *self, void *item);

// //  Push an item to the start of the list, return 0 if OK or -1 if this
// //  failed for some reason(invalid input). Note that if a duplicator has
// //  been set, this method will also duplicate the item.
// int list_push(list_t *self, void *item);

// //  Pop the item off the start of the list, if any
// void *list_pop(list_t *self);

// //  Checks if an item already is present. Uses compare method to determine if
// //  items are equal. If the compare method is NULL the check will only compare
// //  pointers. Returns true if item is present else false.
// bool list_exists(list_t *self, void *item);

// //  Remove the specified item from the list if present
// void list_remove(list_t *self, void *item);

// //  Make a copy of list. If the list has autofree set, the copied list will
// //  duplicate all items, which must be strings. Otherwise, the list will hold
// //  pointers back to the items in the original list. If list is null, returns
// //  NULL.
// //  Caller owns return value and must destroy it when done.
// list_t *list_dup(list_t *self);

// //  Purge all items from list
// void list_purge(list_t *self);

// //  Return number of items in the list
// size_t list_size(list_t *self);

// //  Sort the list. If the compare function is null, sorts the list by
// //  ascending key value using a straight ASCII comparison. If you specify
// //  a compare function, this decides how items are sorted. The sort is not
// //  stable, so may reorder items with the same keys. The algorithm used is
// //  combsort, a compromise between performance and simplicity.
// void list_sort(list_t *self, list_compare_fn_t compare);

// //  Set list for automatic item destruction; item values MUST be strings.
// //  By default a list item refers to a value held elsewhere. When you set
// //  this, each time you append or push a list item, list will take a copy
// //  of the string value. Then, when you destroy the list, it will free all
// //  item values automatically. If you use any other technique to allocate
// //  list values, you must free them explicitly before destroying the list.
// //  The usual technique is to pop list items and destroy them, until the
// //  list is empty.
// void list_autofree(list_t *self);

// //  Sets a compare function for this list. The function compares two items.
// //  It returns an integer less than, equal to, or greater than zero if the
// //  first item is found, respectively, to be less than, to match, or be
// //  greater than the second item.
// //  This function is used for sorting, removal and exists checking.
// void list_comparefn(list_t *self, list_compare_fn_t fn);

// //  Set a free function for the specified list item. When the item is
// //  destroyed, the free function, if any, is called on that item.
// //  Use this when list items are dynamically allocated, to ensure that
// //  you don't have memory leaks. You can pass 'free' or NULL as a free_fn_t.
// //  Returns the item, or NULL if there is no such item.
// void *list_freefn(list_t *self, void *item, list_free_fn_t fn, bool at_tail);
// void list_test(bool verbose);
