//
// Created by roman on 07.10.2020.
//



#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/resource.h>
#include <stdio.h>

int main(){
    struct rusage mem;
    for (int i = 0; i < 10; i++)
    {
        memset(malloc(1000 * 1024 * 1024), '0', 1000 * 1024 * 1024);

        if(getrusage(RUSAGE_SELF, &mem) == 0){
            printf("%ld KB\n", mem.ru_maxrss);
        } else {
            printf("Error");
        }

        sleep(1);
    }

    return 0;
}