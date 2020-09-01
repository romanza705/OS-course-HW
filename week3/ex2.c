//
// Created by roman on 01.09.2020.
//
#include <stdio.h>


void bubble_sort(int *arr, int n){
    for (int i = 0 ; i < n - 1; i++)
    {
        for (int j = 0 ; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j+1] = arr[j] + arr[j+1];
                arr[j] = arr[j+1] - arr[j];
                arr[j+1] = arr[j+1] - arr[j];
            }
        }
    }
}
int main()
{
    int n, d, swap;
    printf("Number of elements:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bubble_sort(arr, n);
    printf("Sorted list:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}



