#include "Header.h"
#include <stdbool.h>
int writeFile(NODE* ptr) {
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
    NODE* tmp;//temp variable for traversal
    while (ptr != NULL) {
        fprintf(fp, "Oder id %d     Pickup Location X:%d Y:%d      Delivery Location X:%d Y:%d  \n",
            ptr->data.orderID,ptr->data.pickup.x, ptr->data.pickup.y, ptr->data.delivery.x,ptr->data.delivery.y);//writing into the file
        tmp = ptr->next;
        ptr = tmp;
    }
    return 0;
}