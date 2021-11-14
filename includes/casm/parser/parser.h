#ifndef CASM_PARSER_H
#define CASM_PARSER_H
#include "casm/COMMON_INCLUDE.h"
#include "casm/data_types/wasm_data.h"

#include "sections/wasm_section_type_pars.h"
#include "sections/wasm_section_functions_pars.h"
#include "sections/wasm_section_code_pars.h"

// TODO Custom section doesnt have to have correct length ?
// main function that goes through the file, reads and creates the wasm_section struct array
int parse_sections(wasm_module* module) {
    WASM_BYTE section_id;
    WASM_BYTE section_length;

    while (1) {
        // we expect a section id byte and a section size byte, otherwise the wasm binary is malformed
        section_id = wasm_file_getc(module->fp); // we expect this line to break when we enter the loop after reading the last section
        if (section_id == 0xFF) break; // get char and check if we haven't reached end-of-file

        section_length = wasm_file_getc(module->fp);
        if (section_length == 0xFF) return PARSER_ERROR; // get char and check if we haven't reached end-of-file

        module->Sections[section_id].id = section_id;
        module->Sections[section_id].length = section_length;
        module->Sections[section_id].pos = wasm_file_ftell(module->fp) - 2; // subtract the id and length byte

//        ifdebug(printf("Section id : %02x with lenght %02x at position %ld ending at pos %ld \n", Sections[section_id].id,
//                       Sections[section_id].length, Sections[section_id].section_fp_start));

        if (wasm_file_fseek(module->fp, section_length, WASM_FILE_SEEK_CUR) != 0) return PARSER_ERROR; // move file cursor by n bytes or exit if eof
    }

    return PARSER_OK;
}


#endif //CASM_PARSER_H
