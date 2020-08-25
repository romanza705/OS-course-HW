////
//// Created by roman on 25.08.2020.
////
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d" , &n) ;
    int w = 2*n - 1;
    int stars = 1;
    int spaces = (w-1)/2;
    for(int j = 0; j < n; j++){

        for(int i = 0; i < spaces; i++){printf("%c", ' ');}
        for(int i = 0; i < stars; i++){printf("%c", '*');}
        for(int i = 0; i < spaces; i++){printf("%c", ' ');}
        spaces--;
        stars+=2;
        printf("\n");
    }


    return 0;

}
