#ifndef CASM_CASM_H
#define CASM_CASM_H

#include "casm/COMMON_INCLUDE.h"
#include "casm/data_types/wasm_data.h"
#include "casm/parser/parser.h"


// this is the main function which takes care of loading a wasm module
// it takes a WASM_FILE and returns a wasm_module
wasm_module* wasm_init(WASM_FILE fp){
    wasm_module* module = malloc(sizeof(wasm_module));
    module->fp = fp;
    return module;
}

int wasm_parse(wasm_module* module){
    // clean the Sections struct for a new reading
    for (int i = 0; i < 12; i++) module->Sections[i].id = SECTION_DOESNT_EXIST;

    // read magic number
    if(wasm_file_fread(module->wasm_descriptor, 4, module->fp) < 1) return PARSER_ERROR; // read 1 byte 4 times, fread returns num of bytes read

    // read version number
    if(wasm_file_fread(module->wasm_version, 4, module->fp) < 1) return PARSER_ERROR; // read 1 byte 4 times, fread returns num of bytes read

    // next byte will/should be the section ID
    if(parse_sections(module) != PARSER_OK) return PARSER_ERROR;

    // now we have a "description" of each section
    // we will parse each section independently
    // here we should handle section reading

    wasm_parse_section_type(module);
    wasm_parse_section_function(module);
    wasm_parse_section_code(module);


    return PARSER_OK;
}


int wasm_parse_print(wasm_module* module){
    printf("\nParsed sections :\n");
    for(int i=0;i<12;i++) if(module->Sections[i].id != SECTION_DOESNT_EXIST)
            printf("Section id : %02x with lenght %02x at position %ld ending at pos %ld \n",
                   module->Sections[i].id,
                   module->Sections[i].length,
                   module->Sections[i].pos,
                   module->Sections[i].pos + module->Sections[i].length);
}




#endif //CASM_CASM_H
