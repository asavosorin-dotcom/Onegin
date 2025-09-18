#ifndef _WORK_
#define _WORK_

#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>



size_t SizeOfFile(const char* filename);
size_t Maxlen(char* buffer);
size_t CountStr(const char* buffer);

#endif