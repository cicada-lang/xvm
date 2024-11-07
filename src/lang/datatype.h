#pragma once

datatype_t *datatype_new(const word_t *name);
void datatype_destroy(datatype_t **self_pointer);

void datatype_close(datatype_t *self);
bool datatype_is_closed(datatype_t *self);

void datatype_add_data_constructor(datatype_t *self, word_t *name, size_t arity);
