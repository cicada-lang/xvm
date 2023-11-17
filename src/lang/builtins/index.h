#pragma once

#include "stdio/index.h"
#include "int/index.h"
#include "bool/index.h"
#include "string/index.h"
#include "word/index.h"
#include "vm/index.h"

void define_all_builtins(vm_t *self);
