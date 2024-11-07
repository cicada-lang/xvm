#pragma once

data_constructor_t *data_constructor_new(const datatype_t *datatype, const word_t *name, size_t arity);
void data_constructor_destroy(data_constructor_t **self_pointer);
