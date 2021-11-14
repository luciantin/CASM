#ifndef CASM_WASM_SECTION_TYPE_DATA_H
#define CASM_WASM_SECTION_TYPE_DATA_H


typedef struct __wasm_type_signature{
    WASM_BYTE id;
    long pos;
    __wasm_proto_vector* input_vector;
    __wasm_proto_vector* output_vector;
}__wasm_type_signature;

typedef struct __wasm_section_type{
    int length;
    __wasm_type_signature** types;
}__wasm_section_type;



#endif //CASM_WASM_SECTION_TYPE_DATA_H
