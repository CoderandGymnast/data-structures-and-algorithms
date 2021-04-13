#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int size = 1;
    int* ptr = (int*) malloc(size*sizeof(int));
    printf("%s", &ptr);
    for(int i = 0; i < 100; i++) {
        ptr[i]=1;
    }

    for(int i =0; i < 1000; i++) {
        printf("%d", ptr[i]);
    }

    sleep(1);

    printf("\n%s", &ptr);
};

// 1. There are several solution to implement a dynamic array.
// 2. index out of bound not happen in dynamic array.