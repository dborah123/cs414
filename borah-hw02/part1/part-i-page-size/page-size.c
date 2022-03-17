/*
 * page-faults.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{

    // Create mapping
    char *p = mmap(NULL, 10, PROT_WRITE, MAP_ANONYMOUS, -1, 0);
    if(p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Use physical memory
    *p = 'a';

    // Iterate until we reach end of memory from mmap call
    while (1) {
        p += 1;

        *p = 'a';
    }
    return 1;
}
