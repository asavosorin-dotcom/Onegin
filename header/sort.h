#ifndef _SORT_H
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "struct.h"

void swap(String* struct1, String* struct2);
void bublesort(String* arrate, size_t numOfElem, int (*cmp) (const void* , const void* ));
int my_strcmp(const void* point1, const void* point2);
int my_strcmp_end(const void* point1, const void* point2);
void ArrStructCopy(String* from, String* to);

#endif 