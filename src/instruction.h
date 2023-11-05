#pragma once

#define CALL              ((instruction_t) 0x01)
#define LITERAL_INT       ((instruction_t) 0x02)
#define LITERAL_STRING    ((instruction_t) 0x03)
#define LITERAL_WORD      ((instruction_t) 0x04)
#define LITERAL_BOOLEAN   ((instruction_t) 0x05)
#define LITERAL_NULL      ((instruction_t) 0x06)
#define LITERAL_FLOAT     ((instruction_t) 0x07) // Double-precision floating-point
