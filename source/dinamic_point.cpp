#include "main.h"

int main() {
    
    const char* filename1 = "oneg.txt";
    const char* filename = "oneg.txt";

    FILE* fileout = fopen("output.txt", "w");
        
    Buffer struct_buffer = CreateBuffer(filename);
    // assert(struct_buffer);

    char* buffer = struct_buffer.buff;
    size_t numOfElem = struct_buffer.buff_size;

    Buffer struct_buffer1 = CreateBuffer(filename1);
    // assert(struct_buffer1);


    char* buffer1 = struct_buffer1.buff;
    size_t numOfElem1 = struct_buffer1.buff_size;

    // printf("%s", buffer);
    // size_t maxlen = Maxlen(buffer);
    
    size_t numOfStr = CountStr(buffer + 1);
    String* arr_pointer = (String* ) calloc(numOfStr + 1, sizeof(String));
    
    // printf("%s", arr_pointer[numOfStr].str);

    // printf("Pointer of arr_pointer = %p\n\n", arr_pointer);

    // printf("Size of string = %zu\n", sizeof(String));
    // printf("%zu\n", numOfStr);
    //                      X 
    CreateArrPoint(arr_pointer, buffer + 1);
    
    // OutPutBuffer(bufer);

    fprintf(fileout, "Original text: \n\n");

    OutPutText(fileout, arr_pointer, numOfStr);
    fprintf(fileout, "\n\n\n");
    
    fprintf(fileout, "Sorted Left to Right\n\n");
    printSort(fileout, arr_pointer, numOfStr, *my_strcmp);

    fprintf(fileout, "Sorted Right to Left\n\n");
    printQSort(fileout, arr_pointer, numOfStr, *my_strcmp_end);

    fprintf(fileout, "Original text again\n\n");
    // OutPutText(fileout, arr_pointer, numOfStr);

    OutPutBuf(buffer, fileout, numOfElem);

    fprintf(fileout, "Onegin\n\n\n");

    OutPutBuf(buffer1, fileout, numOfElem1);

    // free(struct_buffer);
    // free(struct_buffer1);

    free(arr_pointer);
    free(buffer);
    free(buffer1);

    fprintf(fileout, "\n");

    fprintf(fileout, "End code\n");

    fclose(fileout);

    return 0;
}



//hello\0\n\n\n\n\n\nhello again

// char* CreateBuffer(const char* filename, FILE* file) {
//     size_t numOfElem = SizeOfFile(filename) / sizeof(char);
//     char* buffer = (char* ) calloc(numOfElem + 2, sizeof(char));

//     size_t numOfElem2 = fread(buffer + 1, sizeof(char), numOfElem + 1, file);

//     return buffer;
// }

void CreateArrPoint(String* arr_pointer, char* buffer) {
    assert(arr_pointer);
    assert(buffer);

    char* str_char = strchr(buffer, '\n');
    // printf("%p\n", str_char);
    // printf("%ld\n", str_char - buffer);

    int i = 0; // Для того чтобы первый был null

    for (; str_char != NULL; i++){

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

void printSort(FILE* fileout, String* arr_pointer, size_t numOfStr, int (*cmp) (const void* , const void* )) {
    bublesort(arr_pointer, numOfStr, *cmp);

    OutPutText(fileout, arr_pointer, numOfStr);

    fprintf(fileout, "\n\n\n");
}

void printQSort(FILE* fileout, String* arr_pointer, size_t numOfStr, int (*cmp) (const void* , const void* )) {
    qsort(arr_pointer, numOfStr, sizeof(String), *cmp); 

    OutPutText(fileout, arr_pointer, numOfStr);

    fprintf(fileout, "\n\n\n");
}

// 1 2 3 2 1 4 5

Buffer CreateBuffer(const char* filename) {
    
    // Buffer* point_struct = (Buffer* ) calloc(1, sizeof(Buffer));
    Buffer point_struct = {0};
    // assert(struct_buf);

    FILE* file = fopen(filename, "r");

    assert(file);

    size_t numOfElem = SizeOfFile(filename) / sizeof(char);
    char* buffer = (char* ) calloc(numOfElem + 2, sizeof(char));
    size_t numOfElemNew = fread(buffer + 1, sizeof(char), numOfElem + 1, file);

    // point_struct->buff = buffer;
    // point_struct->buff_size = numOfElemNew;

    point_struct.buff = buffer;
    point_struct.buff_size = numOfElemNew;

    fclose(file);

    return point_struct;
}

void OutPutBuf(char* buffer, FILE* fileout, size_t numOfElemNew) {
    for (size_t i = 0; i < numOfElemNew; i++) 
        fputc(buffer[i]? buffer[i] : '\n', fileout);

}