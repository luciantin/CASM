#ifndef CASM_WASM_SECTION_CODE_DATA_H
#define CASM_WASM_SECTION_CODE_DATA_H

typedef struct __wasm_section_code{
    int length; // we need the length of the array of __wasm_proto_vectors
    __wasm_proto_vector** functions;
}__wasm_section_code;


#endif //CASM_WASM_SECTION_CODE_DATA_H
