#ifndef _WORK_
#define _WORK_

#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>



int SizeOfFile(const char* filename);
size_t Maxlen(char* buffer);
int CountStr(const char* buffer);

#endif