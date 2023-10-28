#include "index.h"

struct _xvm_t {
    dict_t *dict;
    value_stack_t *value_stack;
    // return_stack_t *return_stack;
};

#define DICT_SIZE 1000003
#define VALUE_STACK_SIZE 10000
#define RETURN_STACK_SIZE 10000

xvm_t *
xvm_create(void) {
    xvm_t *self = (xvm_t *) calloc(1, sizeof(xvm_t));
    self->dict = dict_create(DICT_SIZE);
    self->value_stack = value_stack_create(VALUE_STACK_SIZE);
    return self;
}

void
xvm_destroy(xvm_t **self_p) {
    assert(self_p);
    if (*self_p) {
        xvm_t *self = *self_p;
        dict_destroy(&self->dict);
        value_stack_destroy(&self->value_stack);
        free(self);
        *self_p = NULL;
    }
}

word_t *
xvm_word(xvm_t *self, const char *name) {
    return dict_word(self->dict, name);
}

program_t *
xvm_program(xvm_t *self, const char *name) {
    word_t *word = xvm_word(self, name);
    return word_program(word);
}

value_t
xvm_value_stack_pop(xvm_t *self) {
    return value_stack_pop(self->value_stack);
}

void
xvm_value_stack_push(xvm_t *self, value_t value) {
    value_stack_push(self->value_stack, value);
}

void
xvm_step(xvm_t *self) {
    printf("xvm_step todo: %ld\n", (uint64_t) self);
}

void
xvm_run(xvm_t *self) {
    xvm_step(self);
}
