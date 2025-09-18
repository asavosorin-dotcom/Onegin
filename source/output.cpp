#include "output.h"

void OutPutText(String* arr_pointer, size_t numOfStr) { 
    for (size_t i = 0; i < numOfStr; i++) {
        puts(arr_pointer[i].str);
        // printf("%s %lu\n", arr_pointer[i].str, arr_pointer[i].size_str);
        // printf("%s %lu\n", arr_pointer[i].str, arr_pointer[i].size_str);
    }
}
