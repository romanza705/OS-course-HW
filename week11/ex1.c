//
// Created by roman on 27.10.2020.
//

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    struct stat statbuf;

    FILE *file = open("/home/roman/OS-course-HW/week11/ex1.txt", O_RDWR, 0666);
    if (file == -1) {
        fprintf(stderr, "%s\n", strerror(errno));
        return -1;
    }
    if (fstat(file, &statbuf)) {
        fprintf(stderr, "%s\n", strerror(errno));
        return -1;
    }
    char *addr;
    addr = mmap(NULL, statbuf.st_size, PROT_WRITE, MAP_SHARED, file, 0);
    if (addr == MAP_FAILED) {
        fprintf(stderr, "%s\n",strerror(errno));
        return -1;
    }
    ftruncate(file, sizeof(char)*18);
    strncpy(addr, "This is a nice day", statbuf.st_size);
    munmap(addr, statbuf.st_size);
    close(file);
    return 0;
}
