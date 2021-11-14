#ifndef CASM_WASM_SECTION_FUNCTIONS_PARS_H
#define CASM_WASM_SECTION_FUNCTIONS_PARS_H

#include "casm/COMMON_INCLUDE.h"
#include "casm/data_types/wasm_data.h"


int __parse_section_function(wasm_module* module){
    WASM_BYTE num_of_functions;
    WASM_BYTE data, tmp;

    num_of_functions = wasm_file_getc(module->fp);  if(num_of_functions == 0xFF) return PARSER_ERROR; // get the number of types
    printf("number of functions : %ld", num_of_functions);

    if (wasm_file_fseek(module->fp, -1, WASM_FILE_SEEK_CUR) != 0) return PARSER_ERROR; // move file cursor by n bytes or exit if eof

    module->section_functions = malloc(sizeof(__wasm_section_type));

    module->section_functions->signature = __malloc_wasm_vector();
    __read_wasm_vector(module->fp, module->section_functions->signature);
    __print_wasm_vector(module->section_functions->signature);

    return PARSER_OK;
}

int wasm_parse_section_function(wasm_module* module){
    printf("\nMoving to pos : %ld\n",module->Sections[WASM_SECTION_CODE_FUNCTION].pos + 2);

    if (wasm_file_fseek(module->fp, module->Sections[WASM_SECTION_CODE_FUNCTION].pos + 2, WASM_FILE_SEEK_SET) != 0) return PARSER_ERROR; // move file cursor by n bytes or exit if eof
    if(__parse_section_function(module) != PARSER_OK) return PARSER_ERROR;

    return PARSER_OK;
}


#endif //CASM_WASM_SECTION_FUNCTIONS_PARS_H
