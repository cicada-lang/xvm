#pragma once

type_constructor_t *type_constructor_create(size_t arity);
void type_constructor_destroy(type_constructor_t **self_pointer);
