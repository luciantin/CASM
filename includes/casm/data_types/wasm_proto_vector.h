#ifndef CASM_WASM_PROTO_VECTOR_H
#define CASM_WASM_PROTO_VECTOR_H


typedef struct __wasm_proto_vector__ {
    long length;
    WASM_BYTE* data;
}__wasm_proto_vector;



// this function expects fp to be at the start of a vector, i.e. at the length byte followed by the vector elements
static inline int __read_wasm_vector(WASM_FILE fp, __wasm_proto_vector* _vector){
    _vector->length = wasm_file_getc(fp);  if(_vector->length == 0xFF) return PARSER_ERROR; // get the number of types
    _vector->data = malloc(sizeof(WASM_BYTE)*_vector->length);
    if(wasm_file_fread(_vector->data, _vector->length, fp) < 1) return PARSER_ERROR; // read 1 byte 4 times, fread returns num of bytes read
    return PARSER_OK;
}

// this function expects fp to be at the start of a vector, i.e. at the length byte followed by the vector elements
static inline int __print_wasm_vector(__wasm_proto_vector* _vector){
    printf("\nVector content : ");
    for(int i = 0; i<_vector->length; i++) printf(" 0x%02x ", _vector->data[i]);
    return PARSER_OK;
}

static inline void __free_wasm_vector(__wasm_proto_vector* _vector){
    free(_vector->data);
}

static inline void* __malloc_wasm_vector(){
    return malloc(sizeof(__wasm_proto_vector));
}

#endif //CASM_WASM_PROTO_VECTOR_H
