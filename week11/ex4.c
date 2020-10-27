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
    char *in, *out;
    struct stat statbuf;

    int input = open("/home/roman/OS-course-HW/week11/ex1.txt", O_RDONLY);
    int output = open("/home/roman/OS-course-HW/week11/ex1.memcp.txt", O_RDWR);
    if (input == -1) {
        fprintf(stderr, "in: %s\n", strerror(errno));
        return -1;
    }
    if (output == -1) {
        fprintf(stderr, "out: %s\n", strerror(errno));
        return -1;
    }
    if (fstat(input, &statbuf)) {
        fprintf(stderr, "%s\n", strerror(errno));
        return -1;
    }

    in = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, input, 0);
    ftruncate(output, statbuf.st_size);
    out = mmap(NULL, statbuf.st_size, PROT_WRITE, MAP_SHARED, output, 0);
    memcpy(out, in, statbuf.st_size);
    munmap(in, statbuf.st_size);
    munmap(out, statbuf.st_size);
    close(input);
    close(output);
    return 0;
}