#include "index.h"

struct _word_t {
    char *name;
    program_t *program;
    program_t *type_program;
    primitive_t *primitive;
    word_t *next;
};

word_t *
word_create(const char *name) {
    word_t *self = allocate(sizeof(word_t));
    self->name = string_dup(name);
    return self;
}

void
word_destroy(word_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        word_t *self = *self_pointer;
        free(self->name);
        program_destroy(&self->program);
        program_destroy(&self->type_program);
        word_destroy(&self->next);
        free(self);
        *self_pointer = NULL;
    }
}

const char *
word_name(word_t *self) {
    return self->name;
}

program_t *
word_program(word_t *self) {
    return self->program;
}

void
word_program_set(word_t *self, program_t *program) {
    self->program = program;
}

program_t *
word_type_program(word_t *self) {
    return self->type_program;
}

void
word_type_program_set(word_t *self, program_t *type_program) {
    self->type_program = type_program;
}

primitive_t *
word_primitive(word_t *self) {
    return self->primitive;
}

void
word_primitive_set(word_t *self, primitive_t *primitive) {
    self->primitive = primitive;
}
