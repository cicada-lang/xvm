#pragma once

typedef uint8_t byte_t;
typedef byte_t instruction_t;
typedef uintptr_t value_t;
typedef int64_t int_t;

typedef struct _dict_t dict_t;
typedef struct _word_t word_t;
typedef struct _program_t program_t;
typedef struct _value_stack_t value_stack_t;
typedef struct _frame_t frame_t;
typedef struct _return_stack_t return_stack_t;
typedef struct _token_t token_t;
typedef struct _vm_t vm_t;

typedef void (primitive_t)(vm_t *vm);
