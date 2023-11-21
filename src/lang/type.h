#include "index.h"

type_t *type_var_create(const char *name);
type_t *type_term_create(const char *name, size_t arity);
void type_destroy(type_t **self_pointer);
