typedef uint8_t byte_t;
typedef byte_t instruction_t;
typedef uint64_t value_t;

typedef struct _dict_t dict_t;
typedef struct _word_t word_t;
typedef struct _program_t program_t;
typedef struct _value_stack_t value_stack_t;
typedef struct _return_frame_t return_frame_t;
typedef struct _return_stack_t return_stack_t;
typedef struct _xvm_t xvm_t;

typedef void (primitive_t)(xvm_t *vm);
