#ifndef CASM_WASM_SECTION_FUNCTION_DATA_H
#define CASM_WASM_SECTION_FUNCTION_DATA_H


typedef struct __wasm_section_function{
//    int length; // length is saved inside the __wasm_proto_vector
    __wasm_proto_vector* signature;
}__wasm_section_function;


#endif //CASM_WASM_SECTION_FUNCTION_DATA_H
