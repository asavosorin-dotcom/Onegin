
// #include <TXLib.h>

#include "main.h"

// char* my_strdup(const char *s);

int main() {
    
    const char* filename = {"sheks.txt"};
    FILE* file = fopen(filename, "r");
    // const char* filename = {"oneg.txt"};

    char* buffer = CreateBuffer(filename, file);

    // printf("%s", buffer);

    // size_t maxlen = Maxlen(buffer);
    
    size_t numOfStr = CountStr(buffer + 1);

    String* arr_pointer = (String* ) calloc(numOfStr + 1, sizeof(String));
    
    // printf("%s", arr_pointer[numOfStr].str);

    // printf("Pointer of arr_pointer = %p\n\n", arr_pointer);

    // printf("Size of string = %zu\n", sizeof(String));
    // printf("%zu\n", numOfStr);
    
    CreateArrPoint(arr_pointer, buffer + 1);
    
    // OutPutBuffer(bufer);

    printf("Original text: \n\n");

    OutPutText(arr_pointer, numOfStr);
    printf("\n\n\n");
    
    printf("Sorted Left to Right\n\n");
    printSort(arr_pointer, numOfStr, *my_strcmp);

    printf("Sorted Right to Left\n\n");
    printSort(arr_pointer, numOfStr, *my_strcmp_end);

    printf("Original text again\n\n");
    OutPutText(arr_pointer, numOfStr);

    free(arr_pointer);
    free(buffer);

    printf("\n");

    printf("End code\n");

    fclose(file);
}



//hello\0\n\n\n\n\n\nhello again

char* CreateBuffer(const char* filename, FILE* file) {
    size_t numOfElem = SizeOfFile(filename) / sizeof(char);
    char* buffer = (char* ) calloc(numOfElem + 2, sizeof(char));

    fread(buffer + 1, sizeof(char), numOfElem + 1, file);

    return buffer;
}

void CreateArrPoint(String* arr_pointer, char* buffer) {
    assert(arr_pointer);
    assert(buffer);

    char* str_char = strchr(buffer, '\n');
    // printf("%p\n", str_char);
    // printf("%ld\n", str_char - buffer);

    int i = 0; // Для того чтобы первый был null

    for (; str_char != NULL; i++){

        assert(str_char);

        *str_char = '\0';
        
        (arr_pointer + i) -> str = buffer;
        (arr_pointer + i) -> str_end = str_char - 1;
        
        str_char += 1;

        while (*str_char == '\n') {
            str_char++;
        }

        buffer = str_char;
        str_char = strchr(buffer, '\n');
        // printf("Pointer [%d] %p\n", i, buffer);

    }
    
    str_char = strchr(buffer, '\0');

    arr_pointer[i].str = buffer;
    arr_pointer[i].str_end = str_char - 1;
}

void printSort(String* arr_pointer, size_t numOfStr, int (*cmp) (String* , String* )) {
    String* sortedLtoR = bublesort(arr_pointer, numOfStr, *cmp); 

    OutPutText(sortedLtoR, numOfStr);
    
    free(sortedLtoR);

    printf("\n\n\n");
}
