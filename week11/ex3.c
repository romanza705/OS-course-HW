//
// Created by roman on 27.10.2020.
//

#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Hello");
    fork();
    printf("\n");
    return 0;
}

//int main(void) {
//    printf("Hello\n");
//    fork();
//    printf("\n");
//    return 0;
//}