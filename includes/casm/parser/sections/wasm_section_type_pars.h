#ifndef CASM_WASM_SECTION_H
#define CASM_WASM_SECTION_H

#include "casm/COMMON_INCLUDE.h"
#include "casm/data_types/wasm_data.h"


// this function expects that the fp is positioned at the start of the section data, after the section id and length
static inline int __wasm_parse_section_type(wasm_module* module){
    WASM_BYTE num_of_types;
    WASM_BYTE data, tmp;

    num_of_types = wasm_file_getc(module->fp);  if(num_of_types == 0xFF) return PARSER_ERROR; // get the number of types
    printf("number of types : %ld", num_of_types);

    module->section_type = malloc(sizeof(__wasm_section_type));
    module->section_type->types = malloc(sizeof(__wasm_type_signature*)*num_of_types);
    module->section_type->length = num_of_types;

    // PROCESS SECTION
    for(int i = 0; i<num_of_types; i++){

        module->section_type->types[i] = malloc(sizeof(__wasm_type_signature));
        module->section_type->types[i]->pos = wasm_file_ftell(module->fp);

        // type definition byte
        data = wasm_file_getc(module->fp);  if(data == 0xFF) break; // get char and check if we haven't reached end-of-file
        module->section_type->types[i]->id = data; // probably not going to be used as only 0x60 is defined in the spec, for functions


        printf("\nType : %02x at pos %ld",data,module->section_type->types[i]->pos);

        // we expect 2 vectors and their length, for each "type"

        module->section_type->types[i]->input_vector = __malloc_wasm_vector();
        module->section_type->types[i]->output_vector = __malloc_wasm_vector();

        __read_wasm_vector(module->fp, module->section_type->types[i]->input_vector);
        __read_wasm_vector(module->fp, module->section_type->types[i]->output_vector);

        __print_wasm_vector(module->section_type->types[i]->input_vector);
        __print_wasm_vector(module->section_type->types[i]->output_vector);
    }

    return PARSER_OK;
}


int wasm_parse_section_type(wasm_module* module){
    printf("\nMoving to pos : %ld\n",module->Sections[WASM_SECTION_CODE_TYPE].pos + 2);

    if (wasm_file_fseek(module->fp, module->Sections[WASM_SECTION_CODE_TYPE].pos + 2, WASM_FILE_SEEK_SET) != 0) return PARSER_ERROR; // move file cursor by n bytes or exit if eof
    if(__wasm_parse_section_type(module) != PARSER_OK) return PARSER_ERROR;

    return PARSER_OK;
}



#endif //CASM_WASM_SECTION_H
