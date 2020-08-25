//
// Created by roman on 25.08.2020.
//
#include <stdio.h>
#include <string.h>

int main() {
    char word[256];
    scanf("%s" , word) ;
    for (int i = strlen(word); i >= 0; i--){
        printf("%c", word[i]);
    }

    return 0;

}
