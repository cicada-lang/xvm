#include "index.h"

struct frame_t {
    size_t index;
    const program_t *program;
    list_t *local_variable_list;
};

typedef struct {
    const word_t *word;
    value_t value;
} local_variable_t;

static local_variable_t *
local_variable_new(const word_t *word, value_t value) {
    local_variable_t *self = allocate(sizeof(local_variable_t));
    self->word = word;
    self->value = value;
    return self;
}

static void
local_variable_destroy(local_variable_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        local_variable_t *self = *self_pointer;
        free(self);
        *self_pointer = NULL;
    }
}


frame_t *
frame_new(const program_t *program) {
    frame_t *self = allocate(sizeof(frame_t));
    self->index = 0;
    self->program = program;
    self->local_variable_list = list_new();
    return self;
}

void
frame_destroy(frame_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        frame_t *self = *self_pointer;
        list_destroy(&self->local_variable_list, free);
        free(self);
        *self_pointer = NULL;
    }
}

bool
frame_is_end(frame_t *self) {
    return self->index >= program_byte_size(self->program);
}

byte_t
frame_fetch_byte(frame_t *self) {
    byte_t byte = program_fetch_byte(self->program, self->index);
    self->index += sizeof(byte_t);
    return byte;
}

opcode_t
frame_fetch_opcode(frame_t *self) {
    return (opcode_t) frame_fetch_byte(self);
}

value_t
frame_fetch_value(frame_t *self) {
    value_t value = program_fetch_value(self->program, self->index);
    self->index += sizeof(value_t);
    return value;
}

word_t *
frame_fetch_word(frame_t *self) {
    word_t *word = program_fetch_word(self->program, self->index);
    self->index += sizeof(word_t *);
    return word;
}

void
frame_set_local_variable(frame_t *self, word_t *word, value_t value) {
    local_variable_t *local_variable = local_variable_new(word, value);
    list_push(self->local_variable_list, local_variable);
}

value_t
frame_get_local_variable(frame_t *self, word_t *word) {
    local_variable_t *local_variable = list_end(self->local_variable_list);
    while (local_variable) {
        if (local_variable->word == word) {
            list_remove(self->local_variable_list, local_variable);
            value_t value = local_variable->value;
            local_variable_destroy(&local_variable);
            return value;
        }

        local_variable = list_prev(self->local_variable_list);
    }

    printf("[frame_get_local_variable] word name: %s\n", word_name(word));
    assert(false && "[frame_get_local_variable] undefined local name.");
}
