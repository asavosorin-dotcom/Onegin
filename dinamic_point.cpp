// #include <TXLib.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <fcntl.h>
#include <string.h>

typedef struct {
    char* str;
    size_t size_str;
} String;

int SizeOfFile(const char* filename);
size_t Maxlen(char* buffer);
int CountStr(const char* buffer);
void CreateArrPoint(String* arr_pointer, char* buffer);
void OutPutText(String* arr_pointer, int numOfStr);
// char* my_strdup(const char *s);


int main() {
    
    const char* filename = {"sheks.txt"};
    // const char* filename = {"oneg.txt"};

    FILE* file = fopen(filename, "r");

    size_t numOfElem = SizeOfFile(filename) / sizeof(char);
    char* buffer = (char* ) calloc(numOfElem + 1, sizeof(char));
    fread(buffer, sizeof(char), numOfElem + 1, file);

    // printf("%s", buffer);

    // size_t maxlen = Maxlen(buffer);
    
    size_t numOfStr = CountStr(buffer);

    String* arr_pointer = (String* ) calloc(numOfStr + 1, sizeof(String));
    
    printf("Pointer of arr_pointer = %p\n", arr_pointer);

    // printf("Size of string = %zu\n", sizeof(String));
    // printf("%zu\n", numOfStr);
    
    CreateArrPoint(arr_pointer, buffer);
    
    OutPutText(arr_pointer, numOfStr);

    free(arr_pointer);
    free(buffer);

    printf("\n");
    fclose(file);
}

int SizeOfFile(const char* filename) {
    struct stat my_stat = {};
    int description = open(filename,  O_RDONLY);
    
    assert(description != -1);

    fstat(description, &my_stat);

    // printf("Size = %ld\n", my_stat.st_size);

    return my_stat.st_size;
}

void CreateArrPoint(String* arr_pointer, char* buffer) {
    assert(arr_pointer);
    assert(buffer);

    char* str_char = strchr(buffer, '\n');
    // printf("%p\n", str_char);
    // printf("%ld\n", str_char - buffer);

    int i = 0;

    for (; str_char != NULL; i++){

        assert(str_char);

        *str_char = '\0';
        str_char += 1;
        
        (arr_pointer + i) -> str = buffer;
        (arr_pointer + i) -> size_str = str_char - buffer;
        
        buffer = str_char;
        str_char = strchr(buffer, '\n');
        // printf("Pointer [%d] %p\n", i, buffer);

    }
    
    str_char = strchr(buffer, '\0');

    arr_pointer[i].str = buffer;
    arr_pointer[i].size_str = str_char - buffer;
}

int CountStr(const char* buffer) { // ������� ���������� �����
    
    int count = 0;
    
    while (*buffer != '\0') {
        if (*buffer == '\n') {
            count++;
        } 
        buffer++;
    }

    printf("Count = %d\n", count + 1);

    return ++count;
}

char* my_strdup(const char *s) {
    char* new_s = (char* ) calloc(strlen(s), sizeof(char));
    if (new_s == NULL) {
        return NULL;
    }

    int i = 0;

    while (*s != '\0') {
        *new_s++ = *s++;
        i++;
    }
    *new_s = '\0';

    return new_s - i;
}

void OutPutText(String* arr_pointer, int numOfStr) { // Спросить у Саши, что ха хуйня с выводом длины
    for (int i = 0; i < (int) numOfStr; i++) {
        // puts(arr_pointer[i].str);
        printf("%s %lu\n", arr_pointer[i].str, arr_pointer[i].size_str);
    }
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

    return maxlen;
}

char* bublesort(char* arrate, size_t numOfElem) {
    
    for (size_t j = 0; j < numOfElem; j++){
        
        char* elem1 = &arrate[0];
        char* elem2 = &arrate[1];
        
        // printf("[%ld]\n", j);

        for (size_t i = 1; i < numOfElem; i++) { // Ставит наибольший элемент в конец
            if (*elem1 > *elem2) {
                swap(elem1, elem2);
            }
            elem1 = &arrate[i];
            elem2 = &arrate[i + 1];
        }
    }

    return arrate;    

}

void swap(char* elem1, char* elem2) {
    char c = *elem2;
    *elem2 = *elem1;
    *elem1 = c;
}

void SortRtoL(String* arr_pointer) { // Написать сортировку

}