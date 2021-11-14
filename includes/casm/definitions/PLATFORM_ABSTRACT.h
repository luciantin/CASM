#ifndef CASM_PLATFORM_ABSTRACT_H
#define CASM_PLATFORM_ABSTRACT_H

// a list of functions and types that the whole library uses, which are also platform dependant
// or can be abstracted to use a different ex. file reader

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define ifdebug(a);  if(DEBUG) a


/////////////////////////////////////////
#define WASM_BYTE unsigned char
#define WASM_FILE_SEEK_CUR SEEK_CUR
#define WASM_FILE_SEEK_SET SEEK_SET
#define WASM_FILE_SEEK_END SEEK_END
#define WASM_FILE FILE*

static inline long      wasm_file_ftell(WASM_FILE fp){                          return ftell(fp); }
static inline int       wasm_file_fseek(WASM_FILE fp, long bytes, int from){    return fseek(fp, bytes, from); }
static inline size_t    wasm_file_fread(WASM_BYTE* p, size_t n, WASM_FILE fp){  return fread(p, sizeof(WASM_BYTE), n, fp); }
static inline int       wasm_file_getc(WASM_FILE fp){                           return getc(fp); }
/////////////////////////////////////////


#endif //CASM_PLATFORM_ABSTRACT_H
