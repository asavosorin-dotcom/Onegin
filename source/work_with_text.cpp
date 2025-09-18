#include "work_with_text.h"

size_t SizeOfFile(const char* filename) {
    struct stat my_stat = {};
    int description = open(filename,  O_RDONLY);
    
    assert(description != -1);

    fstat(description, &my_stat);

    // printf("Size = %ld\n", my_stat.st_size);

    return (size_t) my_stat.st_size;
}

size_t CountStr(const char* buffer) {
    
    size_t count = 0;
    
    while (*buffer != '\0') {
        
        if (*buffer == '\n') {
            count++;
            buffer++;

            while (*buffer == '\n') {
                buffer++;
            }
        } else {
            buffer++;
        }
           
    }

    // printf("Count = %d\n\n", count + 1);

    return ++count;
}

size_t Maxlen(char* buffer) {
    
    int maxlen = 0;
    int count = 0;

    while (*buffer != '\0') {
        if (*buffer == '\n') {
            
            if (count > maxlen)
                maxlen = count;

            count = 0;
        }

        buffer++;
        count++;
    }

    printf("MaxLen = %d\n", maxlen);

    return (size_t) maxlen;
}