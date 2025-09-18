#ifndef _SORT_H
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct.h"

void swap(String* struct1, String* struct2);
String* bublesort(String* arr, size_t numOfElem, int (*cmp) (String* , String* ));
int my_strcmp(String* strct1, String* strct2);
int my_strcmp_end(String* strct1, String* strct2);
void ArrStructCopy(String* from, String* to);

#endif