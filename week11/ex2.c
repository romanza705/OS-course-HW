//
// Created by roman on 27.10.2020.
//


#include <stdio.h>
#include <unistd.h>

int main() {
    char* word = "Hello";
    for(int i=0; i<5; i++){
        printf("%c", word[i]);
        sleep(1);
    }
}