//
// Created by roman on 08.09.2020.
//

#include <stdio.h>
#include <unistd.h>

int main(){
    int n = getpid();
    fork();
    int pid = getpid();

    if(n == pid){
        printf("Hello from parent [PID - %d]\n", n);
    } else {
        printf("Hello from child [PID - %d]\n", pid);
    }
    return 0;
}
//Hello from parent [PID - 11357]
//Hello from child [PID - 11358]
//Hello from parent [PID - 11393]
//Hello from child [PID - 11399]
//Hello from parent [PID - 11433]
//Hello from child [PID - 11434]
//Hello from parent [PID - 11466]
//Hello from child [PID - 11468]
//Hello from parent [PID - 11500]
//Hello from child [PID - 11502]
//Hello from parent [PID - 11531]
//Hello from child [PID - 11533]
//Hello from parent [PID - 11565]
//Hello from child [PID - 11567]
//Hello from parent [PID - 11596]
//Hello from child [PID - 11597]
//Hello from parent [PID - 11626]
//Hello from child [PID - 11628]
//Hello from parent [PID - 11660]
//Hello from child [PID - 11662]
//The pid gets, then fork() creates copy of process.
// If repeated get of pid doesnt change, so we are still in parent process
//Otherwise we are in child process