#ifndef CASM_WASM_DATA_H
#define CASM_WASM_DATA_H

// this header should include all wasm data types

#include "wasm_proto_vector.h"

#include "casm/data_types/sections/wasm_section_type_data.h"
#include "casm/data_types/sections/wasm_section_function_data.h"
#include "casm/data_types/sections/wasm_section_code_data.h"

#include "../COMMON_INCLUDE.h"

// These are the base structs which define a wasm module and each section
//

typedef struct wasm_section{
    int id;
    long pos;
    WASM_BYTE length;
} __wasm_section;


// structure which defines a wasm module
typedef struct wasm_module{
    __wasm_section Sections[16]; // should be only 12

    __wasm_section_type* section_type;
    __wasm_section_code* section_code;
    __wasm_section_function* section_functions;

    WASM_BYTE wasm_descriptor[4];
    WASM_BYTE wasm_version[4];
    WASM_FILE fp
}wasm_module;



#endif //CASM_WASM_DATA_H
