//
// Created by roman on 29.09.2020.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    printf("Enter N:\n");
    scanf("%d", &N);

    int* arr = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++){
        arr[i] = i;
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}



