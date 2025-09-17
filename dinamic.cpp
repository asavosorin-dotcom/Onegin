#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

int main() {
    struct stat my_stat = {};
    int description = open("oneg.txt",  O_RDONLY);
    
    assert(description != -1);

    fstat(description, &my_stat);

    int size_file = my_stat.st_size;
    printf("my_stat.st_size = %ld\n", my_stat.st_size);

    char* text = (char*) calloc(size_file / sizeof(char), sizeof(char));

    FILE* textf = fopen("oneg.txt", "r");

    int c = fgetc(textf);
    int count = 0;
    
    while (c != EOF) {
        *text++ = c;
        c = fgetc(textf);
        count++;
    }
    
    printf("%s", text - count);

}

