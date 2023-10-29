#pragma once

xvm_t *xvm_create(void);
void xvm_destroy(xvm_t **self_p);
word_t *xvm_word(xvm_t *self, const char *name);
program_t *xvm_program(xvm_t *self, const char *name);
void xvm_primitive_set(xvm_t *self, const char *name, primitive_t *primitive);

value_t xvm_value_stack_pop(xvm_t *self);
void xvm_value_stack_push(xvm_t *self, value_t value);
bool xvm_value_stack_is_empty(xvm_t *self);

frame_t *xvm_return_stack_pop(xvm_t *self);
void xvm_return_stack_push(xvm_t *self, frame_t *frame);
bool xvm_return_stack_is_empty(xvm_t *self);

void xvm_load(xvm_t *self, program_t *program);
void xvm_step(xvm_t *self);
void xvm_run(xvm_t *self);
