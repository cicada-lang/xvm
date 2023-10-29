#include "index.h"

struct _word_t {
    char *name;
    program_t *program;
    primitive_t *primitive;
    word_t *next;
};

word_t *
word_create(const char *name) {
    word_t *self = (word_t *) calloc(1, sizeof(word_t));
    self->name = string_dup(name);
    return self;
}

void
word_destroy(word_t **self_p) {
    assert(self_p);
    if (*self_p) {
        word_t *self = *self_p;
        free(self->name);
        program_destroy(&self->program);
        word_destroy(&self->next);
        free(self);
        *self_p = NULL;
    }
}

const char *
word_name(word_t *self) {
    return self->name;
}

program_t *
word_program(word_t *self) {
    if (self->program) return self->program;

    self->program = program_create();
    return self->program;
}

primitive_t *
word_primitive(word_t *self) {
    return self->primitive;
}

void
word_primitive_set(word_t *self, primitive_t *primitive) {
    self->primitive = primitive;
}
