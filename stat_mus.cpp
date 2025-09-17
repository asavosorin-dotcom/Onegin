#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Read_file(char text[][1000], FILE* file, size_t maxlen, size_t maxStr);

/*

fd = open()

struct stat my_stat = {};

fstat(fd, &my_stat)
close(fd)

1
2
3
4
5
6
7
8
9

//int val[5], val???
*/

//first string
//second string
//third string
//
//str[50] => 0x10           0x15
//unique_str = strdup(fgets(str)) => unique_str == "second string"
//
//stroki[0] = unique_str
//

//0x11
//0x14 == 0x11
//
//strdup(fgets(str))

//stroki =
//str1 => 0x14
//str2 => 0x15
//


int main() {
    
    FILE* file = fopen("oneg.txt", "r");
    
    char text[1000][1000] = {0};

    int count = Read_file(text, file, 1000, 1000);

    for (int i = 0; i < count; i++) {
        printf("%s", text[i]);
    }
}

/*size_t Maxlen(FILE* file) {
    int count = 0;
    char* buff = (char* ) calloc(50, sizeof(int));

    int maxlen = 0;
    while (fgets(buff, 10000, file)) {
        if (strlen(buff) > maxlen) {
            maxlen = strlen(buff);
        }
    }

    return maxlen;
    free(buff);
}*/

/*int Count_str(FILE* file) { // Подсчет количества строк
    int count = 0;
    char* buff = (char* ) calloc(50, sizeof(int));

    for (int i = 0; fgets(buff, 20, file); i++) { // Подсчет количества строк
        count++;
    } 
    
    free(buff);
    return count;
} */

int Read_file(char text[][1000], FILE* file, size_t maxlen, size_t maxStr) { // Считывание файла в двумерный массив
    int count = 0;

    for (int i = 0; i < maxStr; i++) {
        
        if (!fgets(text[i], maxlen, file))
            break;

        count++;
    }

    return count;
}