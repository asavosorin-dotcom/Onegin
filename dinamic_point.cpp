// #include <TXLib.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct { // Структура для строки
    char* str;
    char* str_end;
} String;

int SizeOfFile(const char* filename);
size_t Maxlen(char* buffer);
int CountStr(const char* buffer);
void CreateArrPoint(String* arr_pointer, char* buffer);
void OutPutText(String* arr_pointer, int numOfStr);
void swap(String* struct1, String* struct2);
String* bublesort(String* arrate, size_t numOfElem, int (*cmp) (String* , String*));
void ArrStructCopy(String* from, String* to);
int my_strcmp(String* strct1, String* strct2);
int my_strcmp_end(String* strct1, String* strct2);
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
    
    // printf("%s", arr_pointer[numOfStr].str);

    // printf("Pointer of arr_pointer = %p\n\n", arr_pointer);

    // printf("Size of string = %zu\n", sizeof(String));
    // printf("%zu\n", numOfStr);
    
    CreateArrPoint(arr_pointer, buffer);
    
    // OutPutBuffer(bufer);

    printf("Original text: \n\n");

    OutPutText(arr_pointer, numOfStr);
    printf("\n\n\n");

    
    String* sortedRtoL = bublesort(arr_pointer, numOfStr, *my_strcmp);
    
    printf("Sorted Left to Right\n\n");
    
    OutPutText(sortedRtoL, numOfStr);
    
    free(sortedRtoL);
    
    printf("\n\n\n");
    
    String* sortedLtoR = bublesort(arr_pointer, numOfStr, *my_strcmp_end);
    
    printf("Sorted Right to Left\n\n");

    OutPutText(sortedLtoR, numOfStr);
    
    free(sortedLtoR);

    printf("\n\n\n");

    printf("Original text again\n\n");

    OutPutText(arr_pointer, numOfStr);

    free(arr_pointer);
    free(buffer);

    printf("\n");

    printf("End code\n");

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
        
        (arr_pointer + i) -> str = buffer;
        (arr_pointer + i) -> str_end = str_char - 1;
        
        str_char += 1;

        buffer = str_char;
        str_char = strchr(buffer, '\n');
        // printf("Pointer [%d] %p\n", i, buffer);

    }
    
    str_char = strchr(buffer, '\0');

    arr_pointer[i].str = buffer;
    arr_pointer[i].str_end = str_char - 1;
}

int CountStr(const char* buffer) { // ������� ���������� �����
    
    int count = 0;
    
    while (*buffer != '\0') {
        if (*buffer == '\n') {
            count++;
        } 
        buffer++;
    }

    // printf("Count = %d\n\n", count + 1);

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
        puts(arr_pointer[i].str);
        // printf("%s %lu\n", arr_pointer[i].str, arr_pointer[i].size_str);
        // printf("%s %lu\n", arr_pointer[i].str, arr_pointer[i].size_str);
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

String* bublesort(String* arr, size_t numOfElem, int (*cmp) (String* , String* )) {
    
    String* arrate = (String* ) calloc(numOfElem + 1, sizeof(arr[0]));

    ArrStructCopy(arr, arrate);

    // OutPutText(arrate, numOfElem);

    for (size_t j = 0; j <= numOfElem; j++) {
        
        char* elem1 = arrate[0].str;
        char* elem2 = arrate[1].str;
        
        // printf("[%ld]\n", j);

        for (size_t i = 1; i < numOfElem; i++) { // Ставит наибольший элемент в конец
            
            // printf("[%ld] itaration\n\n\n", i);

            // printf("elem1 = %s\n", elem1);
            // printf("elem2 = %s\n\n", elem2);
        
            // print

            if (cmp(&arrate[i - 1], &arrate[i]) > 0) {
                swap(&arrate[i - 1], &arrate[i]);
                // puts(arrate[i].str);
                // puts(arrate[i + 1].str);
            }

            // printf("After swap\n\n");
            // printf("elem1 = %s\n", arrate[i - 1].str);
            // printf("elem2 = %s\n\n", arrate[i].str);

            // elem1 = arrate[i].str;
            // elem2 = arrate[i + 1].str;

            // printf("elem1 = %s\n", elem1);
            // printf("elem2 = %s\n\n", elem2);

            // if (i == 3) {
            //     break;
            // }
        }

        // break;
    }

    return arrate;    

}

void swap(String* struct1, String* struct2) {
    String c = *struct2;
    
    *struct2 = *struct1;
    *struct1 = c;

}

void ArrStructCopy(String* from, String* to) {
    // printf("Start copy\n\n");
    
    while (from -> str != NULL ) {
        
        // printf("itaration\n\n");

        *to++ = *from++;
    }

    // printf("End copy\n\n");

}

int my_strcmp(String* strct1, String* strct2) {
    return strcmp(strct1->str, strct2->str);
}

int my_strcmp_end(String* strct1, String* strct2) {
    // printf("Start comaprison of end\n");
    
    char* str1 = strct1->str_end;
    char* str2 = strct2->str_end;

    while (!isalpha(*str1)) {
        str1--;
    }

    while (!isalpha(*str2)) {
        str2--;
    }

    while (*str2 == *str1) {
        
        if (isalpha(*str1)) {
            str1--;
        } else {
            while (!isalpha(*str1)) {
                str1--;
            }
        }

        if (isalpha(*str2)) {
            str2--;
        } else {
            while (!isalpha(*str2)) {
                str2--;
            }
        }
    }

    // printf("%c", str1);
    // printf("%c")

    // printf("Return my_strcmp_end: %d\n", *str1 - *str2);

    return (int) (*str1 - *str2);
}