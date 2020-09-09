//
// Created by roman on 08.09.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define COMMAND_MAX_SIZE 100
int main() {
    char *cmd[COMMAND_MAX_SIZE];
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "exit") == 0){
            break;
        }
        system(cmd);
    }
    return 0;
}
