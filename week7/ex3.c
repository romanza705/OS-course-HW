//
// Created by roman on 29.09.2020.
//
#include <stdio.h>
#include <stdlib.h>

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

    a1 = realloc(a1, sizeof(int) * n2);

    for (size_t i = n1; i < n2; i++){
        a1[i] = 0;

    }

    for(i=0; i<n2;i++){
        printf("%d ", a1[i]);
    }


    printf("\n");
    return 0;
}