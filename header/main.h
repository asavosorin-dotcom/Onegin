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

void CreateArrPoint(String* arr_pointer, char* buffer);
void printSort(String* arr_pointer, size_t numOfStr, int (*cmp) (String* , String* ));
char* CreateBuffer(const char* filename, FILE* file);
#endif