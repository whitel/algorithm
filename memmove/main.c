#include<stdio.h>

void *my_memmove(void *src, void *dest, int count) {

    if(src == NULL || dest == NULL || count == 0)   return NULL;

    if(src > dest) {
        for(int i = 0; i < count; ++i)
            *((char*)dest + i) = *((char*)src + i);
    } else {
        for(int i = count - 1; i >= 0; --i)
            *((char*)dest + i) = *((char*)src + i);
    }

    return NULL;
}


void printData(int *data) {
    for(int i = 0; i < 20; ++i) {
        printf("%d, ", data[i]);
    }
    printf("\n");
}


int main() {
    int data[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int *dest = &data[0];

    int *src = &data[5];

    int count = 10;

    printData(data);
    my_memmove(src, dest, count * sizeof(int));
    printData(data);
}
