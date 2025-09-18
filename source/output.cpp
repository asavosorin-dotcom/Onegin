#include "output.h"

void OutPutText(String* arr_pointer, int numOfStr) { 
    for (int i = 0; i < (int) numOfStr; i++) {
        puts(arr_pointer[i].str);
        // printf("%s %lu\n", arr_pointer[i].str, arr_pointer[i].size_str);
        // printf("%s %lu\n", arr_pointer[i].str, arr_pointer[i].size_str);
    }
}
