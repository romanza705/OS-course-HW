//
// Created by roman on 30.09.2020.
//
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>


void * Realloc(void * ptr, size_t newSize){
    if (ptr == NULL){
        return malloc(newSize);
    }
    if (newSize == 0){
        free(ptr);
        return ptr;
    }
    void *tmp = malloc(newSize);
    size_t size = malloc_usable_size(ptr);
    memcpy(tmp, ptr, size);
    free(ptr);
    return tmp;
}

int main(){
    srand(time(NULL)); //I understand what it is but not understand what it for

    printf("Enter original array size: ");
    int n1=0;
    scanf("%d",&n1);

    int* a1 = (int*)malloc(sizeof(int) * n1);
    int i;
    for(i=0; i<n1; i++){
        a1[i] = 100;
        printf("%d ", a1[i]);
    }

    printf("\nEnter new array size: ");
    int n2=0;
    scanf("%d",&n2);

    a1 = Realloc(a1, sizeof(int) * n2);

    for (size_t i = n1; i < n2; i++){
        a1[i] = 0;

    }

    for(i=0; i<n2;i++){
        printf("%d ", a1[i]);
    }


    printf("\n");
    return 0;
}