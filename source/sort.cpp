#include "sort.h"

void swap(char* elem1, char* elem2);
String* bublesort(String* arrate, size_t numOfElem);

String* bublesort(String* arr, size_t numOfElem, int (*cmp) (String* , String* )) {
    
    String* arrate = (String* ) calloc(numOfElem + 1, sizeof(arr[0]));

    ArrStructCopy(arr, arrate);

    // OutPutText(arrate, numOfElem);

    for (size_t j = 0; j <= numOfElem; j++) {
        
        // char* elem1 = arrate[0].str;
        // char* elem2 = arrate[1].str;
        
        // printf("[%ld]\n", j);

        for (size_t i = 1; i < numOfElem; i++) { // Ставит наибольший элемент в конец
            
            // printf("[%ld] itaration\n\n\n", i);

            // printf("elem1 = %s\n", elem1);
            // printf("elem2 = %s\n\n", elem2);
        
            // print

            if (strcmp(arrate[i - 1].str, "\n") == 0 || strcmp(arrate[i].str, "\n") == 0) {
                continue;
            }

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

int my_strcmp(String* strct1, String* strct2) {

    char* str1 = strct1->str;
    char* str2 = strct2->str;

    while (!isalpha(*str1)) {
        str1++;
    }

    while (!isalpha(*str2)) {
        str2++;
    }
 
    for (;*str1 == *str2; *str1++, *str2++) {
        if (*str1 == '\0')
            return 0;
    }

    return *str1 - *str2;

}

int my_strcmp_end(String* strct1, String* strct2) {
    // printf("Start comaprison of end\n");
    
    char* str1 = strct1->str_end;
    char* str2 = strct2->str_end;

    // printf("> char: %c\n", *str1);
    while (!isalpha(*str1)) {
        str1--;
    }

    
    // printf("> char: %c\n", *str1);
    while (!isalpha(*str2)) {
        str2--;
    }

    while ((*str2 == *str1) && (*str1 != '\0') && (*str2 != '\0')) {
        str1--;
        str2--;

        while ((!isalpha(*str1)) && (*str1 != '\0'))
            str1--;

        while ((!isalpha(*str2)) && (*str2 != '\0'))
            str2--;

             //     printf("> 1\n");

        
        // if (isalpha(*str1)) {
            // str1--;
        // } /*else {
            // while ((!isalpha(*str1)) && (*str1 != '\0')) {
            //     printf("> 1\n");
            //     str1--;
            // }
        // }*/

        // if (isalpha(*str2)) {
            // str2--;
        // } /*else {
            // while ((!isalpha(*str2)) && (*str2 != '\0')) {
        //         printf("> 2\n");
        //         str2--;
        //     }
        // }*/
    }

    // printf("%c", str1);
    // printf("%c")

    // printf("Return my_strcmp_end: %d\n", *str1 - *str2);

    return *str1 - *str2;
}

void ArrStructCopy(String* from, String* to) {
    // printf("Start copy\n\n");
    
    while (from -> str != NULL ) {
        
        // printf("itaration\n\n");

        *to++ = *from++;
    }

    // printf("End copy\n\n");

}
