//
// Created by roman on 08.09.2020.
//
#include <stdio.h>
#include<string.h>
#include<sys/types.h>
#include <unistd.h>

int main() {
    for(int i = 0; i < 5; i++){
        fork();
        sleep(5);
    }
    return 0;
}
//when loop to 3
//│      │                 │               ├─gnome-session-b─┬─gnome-shell─┬─clion.sh───java─┬─bash───pstree
//│      │                 │               │                 │             │                 ├─fsnotifier64
//│      │                 │               │                 │             │                 ├─ion.clangd.main───4*[{ion.clangd.main}]
//│      │                 │               │                 │             │                 ├─week4─┬─week4─┬─week4───week4
//│      │                 │               │                 │             │                 │       │       └─week4
//│      │                 │               │                 │             │                 │       ├─week4───week4
//│      │                 │               │                 │             │                 │       └─week4
// first week 4[1] is our program which I execute in CLion, it creates by natural way
// second week4[2] is created by fork() and it is exact copy of week4[1] and it's child
// next fork() creates week4[3] and week4[4] which are childs?children? of week4[1] and week[2]
//it is difficult to explain 3rd iteration, but I hope the principle is understandable
// as in case 3loops was 8 processes, in case of 5 loops will be 32 processes