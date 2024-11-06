#pragma once

typedef uint8_t byte_t;
typedef byte_t opcode_t;
typedef uintptr_t value_t;
typedef int64_t int_t;

typedef struct dict_t dict_t;
typedef struct word_t word_t;
typedef struct program_t program_t;
typedef struct value_stack_t value_stack_t;
typedef struct frame_t frame_t;
typedef struct return_stack_t return_stack_t;
typedef struct token_t token_t;
typedef struct lexer_t lexer_t;
typedef struct interpreter_t interpreter_t;
typedef struct vm_t vm_t;
typedef struct data_constructor_t data_constructor_t;
typedef struct datatype_t datatype_t;

typedef void (primitive_t)(const vm_t *vm);
