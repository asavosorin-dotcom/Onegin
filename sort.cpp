#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* elem1, char* elem2);
char* bublesort(char* arrate, size_t numOfElem);

int main() {
    // char* arrate = "mskdlzdapodf\0";
    char* arrate = (char* ) calloc(13, sizeof(char));
    scanf("%s", arrate);

    puts(bublesort(arrate, 12));
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