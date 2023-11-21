#include "index.h"

type_t *type_var_create(const char *name);
type_t *type_term_create(const char *name, size_t arity);
void type_destroy(type_t **self_pointer);

bool type_is_type_var(const type_t *self);
bool type_is_type_term(const type_t *self);

const char *type_var_name(const type_t *self);
const char *type_term_name(const type_t *self);

void type_term_type_arg_set(const type_t *self, size_t index, type_t *type_arg);
