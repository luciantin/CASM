#include <stdio.h>
#include <stdlib.h>

#include "casm.h"

int main() {

    char file_name[100] = "../examples/wasm_examples/add.wasm";
    FILE *fp;
    fp = fopen(file_name, "r"); // read mode
    if (fp == NULL){ perror("Error while opening the file.\n"); exit(EXIT_FAILURE); }

    wasm_module* module = wasm_init(fp);;
    int parser_return_status = wasm_parse(module);

    if(parser_return_status != PARSER_OK) printf("Parser returned error : %d\n",parser_return_status);
    if(parser_return_status == PARSER_OK) wasm_parse_print(module);



//    printf("\n%d",parse_section_type(fp));

    fclose(fp);
    return 0;
}
