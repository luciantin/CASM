#ifndef CASM_WASM_OP_CODES_H
#define CASM_WASM_OP_CODES_H


#define WASM_SECTION_CODE_CUSTOM (unsigned char)0x00
#define WASM_SECTION_CODE_TYPE (unsigned char)0x01
#define WASM_SECTION_CODE_IMPORT (unsigned char)0x02
#define WASM_SECTION_CODE_FUNCTION (unsigned char)0x03
#define WASM_SECTION_CODE_TABLE (unsigned char)0x04
#define WASM_SECTION_CODE_MEMORY (unsigned char)0x05
#define WASM_SECTION_CODE_GLOBAL (unsigned char)0x06
#define WASM_SECTION_CODE_EXPORT (unsigned char)0x07
#define WASM_SECTION_CODE_START (unsigned char)0x08
#define WASM_SECTION_CODE_ELEMENT (unsigned char)0x09
#define WASM_SECTION_CODE_CODE (unsigned char)0x0a
#define WASM_SECTION_CODE_DATA (unsigned char)0x0b
#define WASM_SECTION_CODE_DATA_COUNT (unsigned char)0x0c


// 0x0_ OP CODES
#define WASM_OP_CODE_UNREACHABLE (unsigned char)0x00
#define WASM_OP_CODE_NOP (unsigned char)0x01
#define WASM_OP_CODE_BLOCK (unsigned char)0x02
#define WASM_OP_CODE_LOOP (unsigned char)0x03
#define WASM_OP_CODE_IF (unsigned char)0x04
#define WASM_OP_CODE_ELSE (unsigned char)0x05
#define WASM_OP_CODE_NOT_USED (unsigned char)0x06
#define WASM_OP_CODE_NOT_USED (unsigned char)0x07
#define WASM_OP_CODE_NOT_USED (unsigned char)0x08
#define WASM_OP_CODE_NOT_USED (unsigned char)0x09
#define WASM_OP_CODE_NOT_USED (unsigned char)0x0a
#define WASM_OP_CODE_END (unsigned char)0x0b
#define WASM_OP_CODE_BR (unsigned char)0x0c
#define WASM_OP_CODE_BR_IF (unsigned char)0x0d
#define WASM_OP_CODE_BR_TABLE (unsigned char)0x0e
#define WASM_OP_CODE_RETURN (unsigned char)0x0f

// 0x1_ OP CODES

// 0x2_ OP CODES

// 0x3_ OP CODES

// 0x4_ OP CODES

// 0x5_ OP CODES

// 0x6_ OP CODES

// 0x7_ OP CODES

// 0x8_ OP CODES

// 0x9_ OP CODES

// 0xa_ OP CODES

// 0xb_ OP CODES

#endif //CASM_WASM_OP_CODES_H
