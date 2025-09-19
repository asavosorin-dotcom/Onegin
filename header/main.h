#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "sort.h"
#include "output.h"
#include "work_with_text.h"

typedef struct {
    char* buff;
    size_t buff_size;
} Buffer; 

Buffer* CreateBuffer(const char* filename);

void CreateArrPoint(String* arr_pointer, char* buffer);
void printSort(FILE* fileout, String* arr_pointer, size_t numOfStr, int (*cmp) (const void* , const void* ));
void OutPutBuf(char* buffer, FILE* fileout, size_t numOfElemNew);
#endif