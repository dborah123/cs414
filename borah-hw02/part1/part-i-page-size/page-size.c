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
    char *p = mmap(NULL, 100000, PROT_WRITE, MAP_ANONYMOUS, -1, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Iterate until we reach end of memory from mmap call
    for (int i = 0; i < 5000; i++) {
        *p = 'a';
        p++;
    }
    return 0;
}
