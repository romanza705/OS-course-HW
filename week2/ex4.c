//
// Created by roman on 25.08.2020.
//

#include <stdio.h>
#include <string.h>
void swap(int *x, int *y)
{
int temp = *x;
*x = *y;
*y = temp;
}

int main() {
    int n;
    int m;
    scanf("%d" , &n) ;
    scanf("%d" , &m) ;
    swap(&n, &m);
    printf("first %d second %d", n , m);
    return 0;

}
