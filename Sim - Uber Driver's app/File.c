#include "Header.h"
#include <stdbool.h>
bool writeFile(NODE* ptr) {
    if (ptr == NULL) {
        printf("NULL Node");
        return -1;
    }
    FILE* fp = NULL;
    fp = fopen("Order details.txt", "w");
    if (fp == NULL) {
        printf("Failed to open the file");
        return 1;
    }
    while (ptr == NULL) {

    }
    return 0;
}