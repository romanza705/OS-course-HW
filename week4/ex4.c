//
// Created by roman on 09.09.2020.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_MAX_SIZE 100
int main(){
    char cmd[COMMAND_MAX_SIZE];
    char path[COMMAND_MAX_SIZE];
    getcwd(path, sizeof(path));
    while(1){
        printf("%s: ", path);
        fgets(cmd, COMMAND_MAX_SIZE, stdin);
        if(strcmp(cmd, "exit") == 0){
            break;
        }
        system(cmd);
    }
    return 0;
}