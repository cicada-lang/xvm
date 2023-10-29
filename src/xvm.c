#include "index.h"

struct _xvm_t {
    dict_t *dict;
    value_stack_t *value_stack;
    return_stack_t *return_stack;
};

#define DICT_SIZE 1000003
#define VALUE_STACK_SIZE 10000
#define RETURN_STACK_SIZE 10000

xvm_t *
xvm_create(void) {
    xvm_t *self = (xvm_t *) calloc(1, sizeof(xvm_t));
    self->dict = dict_create(DICT_SIZE);
    self->value_stack = value_stack_create(VALUE_STACK_SIZE);
    self->return_stack = return_stack_create(RETURN_STACK_SIZE);
    return self;
}

void
xvm_destroy(xvm_t **self_p) {
    assert(self_p);
    if (*self_p) {
        xvm_t *self = *self_p;
        dict_destroy(&self->dict);
        value_stack_destroy(&self->value_stack);
        return_stack_destroy(&self->return_stack);
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

void
xvm_primitive_set(xvm_t *self, const char *name, primitive_t *primitive) {
    word_t *word = xvm_word(self, name);
    word_primitive_set(word, primitive);
}

value_t
xvm_value_stack_pop(xvm_t *self) {
    return value_stack_pop(self->value_stack);
}

void
xvm_value_stack_push(xvm_t *self, value_t value) {
    value_stack_push(self->value_stack, value);
}

bool
xvm_value_stack_is_empty(xvm_t *self) {
    return value_stack_is_empty(self->value_stack);
}

frame_t *
xvm_return_stack_pop(xvm_t *self) {
    return return_stack_pop(self->return_stack);
}

void
xvm_return_stack_push(xvm_t *self, frame_t *frame) {
    return_stack_push(self->return_stack, frame);
}

bool
xvm_return_stack_is_empty(xvm_t *self) {
    return return_stack_is_empty(self->return_stack);
}

void
xvm_load(xvm_t *self, program_t *program) {
    frame_t *frame = frame_create(program);
    xvm_return_stack_push(self, frame);
}

void
xvm_step(xvm_t *self) {
    frame_t *frame = xvm_return_stack_pop(self);
    if (!frame) return;

     execute(self, frame);
    // xvm_return_stack_push(self, frame);
}

void
xvm_run(xvm_t *self) {
    while(!xvm_return_stack_is_empty(self)) {
        xvm_step(self);
    }
}
