#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    printf("size of int %d \n", sizeof i); //4*8 = 32 = 2^32 ... 2^32 / 2 - 1 = 2147483647 is maximal int
    printf("size of float %d \n", sizeof f);
    printf("size of double %d \n", sizeof d);
    printf("the value of int %d \n", i);
    printf("the value of float %f \n", f);
    printf("the value of double %f \n", d);

    return 0;

}
