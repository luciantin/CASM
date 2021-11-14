#ifndef CASM_WASM_SECTION_CODE_PARS_H
#define CASM_WASM_SECTION_CODE_PARS_H

// this function expects that the fp is positioned at the start of the section data, after the section id and length
static inline int __wasm_parse_section_code(wasm_module* module){
    WASM_BYTE num_of_functions;
    WASM_BYTE data, tmp;

    num_of_functions = wasm_file_getc(module->fp);  if(num_of_functions == 0xFF) return PARSER_ERROR; // get the number of types
    printf("number of functions in code : %ld", num_of_functions);

    module->section_code = malloc(sizeof(__wasm_section_code));
    module->section_code->length = num_of_functions;
    module->section_code->functions = malloc(sizeof(__wasm_proto_vector**)*num_of_functions);

    // PROCESS SECTION
    for(int i = 0; i<num_of_functions; i++){

        module->section_code->functions[i] = __malloc_wasm_vector();
        __read_wasm_vector(module->fp, module->section_code->functions[i]);
        __print_wasm_vector(module->section_code->functions[i]);
    }

    return PARSER_OK;
}


int wasm_parse_section_code(wasm_module* module){
    printf("\nMoving to pos : %ld\n",module->Sections[WASM_SECTION_CODE_CODE].pos + 2);

    if (wasm_file_fseek(module->fp, module->Sections[WASM_SECTION_CODE_CODE].pos + 2, WASM_FILE_SEEK_SET) != 0) return PARSER_ERROR; // move file cursor by n bytes or exit if eof
    if(__wasm_parse_section_code(module) != PARSER_OK) return PARSER_ERROR;

    return PARSER_OK;
}


#endif //CASM_WASM_SECTION_CODE_PARS_H
