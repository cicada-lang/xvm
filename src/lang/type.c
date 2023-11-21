#include "index.h"

enum type_tag_t {
    TYPE_VAR,
    TYPE_TERM,
};

typedef struct _type_var_t type_var_t;
typedef struct _type_term_t type_term_t;

struct _type_var_t {
    char *name;
};

struct _type_term_t {
    char *name;
    size_t arity;
    type_t **type_args;
};

struct _type_t {
    enum type_tag_t tag;
    union {
        type_var_t *type_var;
        type_term_t *type_term;
    };
};

type_t *
type_var_create(const char *name) {
    type_t *self = allocate(sizeof(type_t));
    self->tag = TYPE_VAR;
    self->type_var = allocate(sizeof(type_var_t));
    self->type_var->name = string_dup(name);
    return self;
}

type_t *
type_term_create(const char *name, size_t arity) {
    type_t *self = allocate(sizeof(type_t));
    self->tag = TYPE_TERM;
    self->type_term = allocate(sizeof(type_term_t));
    self->type_term->name = string_dup(name);
    self->type_term->arity = arity;
    self->type_term->type_args = allocate_array(arity, sizeof(type_t));
    return self;
}

void
type_destroy(type_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        type_t *self = *self_pointer;
        if (self->tag == TYPE_VAR) {
            free(self->type_var->name);
            free(self->type_var);
        } else if (self->tag == TYPE_TERM) {
            free(self->type_term->name);
            for (size_t i = 0; i < self->type_term->arity; i++) {
                type_destroy(&self->type_term->type_args[i]);
            }

            free(self->type_term->type_args);
        }

        free(self);
        *self_pointer = NULL;
    }
}

bool
type_is_type_var(const type_t *self) {
    return self->tag == TYPE_VAR;
}

bool
type_is_type_term(const type_t *self) {
    return self->tag == TYPE_TERM;
}

const char *
type_var_name(const type_t *self) {
    assert(type_is_type_var(self));
    return self->type_var->name;
}

const char *
type_term_name(const type_t *self) {
    assert(type_is_type_term(self));
    return self->type_term->name;
}

void
type_print(const type_t *self) {
    if (type_is_type_var(self)) {
        printf("%s", type_var_name(self));
    } else if (type_is_type_term(self)) {
        // TODO Also print prepend args.
        for (size_t i = 0; i < type_term_arity(self); i++) {
            type_print(type_term_type_arg_get(self, i));
            printf(" ");
        }

        printf("%s", type_term_name(self));
    }
}

size_t
type_term_arity(const type_t *self) {
    assert(type_is_type_term(self));
    return self->type_term->arity;
}

const type_t *
type_term_type_arg_get(const type_t *self, size_t index) {
    assert(type_is_type_term(self));
    return self->type_term->type_args[index];
}


void
type_term_type_arg_set(const type_t *self, size_t index, type_t *type_arg) {
    assert(type_is_type_term(self));
    self->type_term->type_args[index] = type_arg;
}
