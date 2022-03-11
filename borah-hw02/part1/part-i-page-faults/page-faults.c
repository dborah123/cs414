/*
 * page-faults.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int
main(int argc, char *argv[])
{

    /**
     * Causing page fault that is handled successfully (adding a new mapping)
     */
    char *p = mmap(NULL, 10, PROT_WRITE, MAP_ANONYMOUS, -1, 0);
    if(p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    *p = 'h';

    /**
     * Causing page fault that isn't handled successfully (attempting to access an
     * area of outside of process's permission. This should cause a segfault.
     */
    int *bad_address = 0x0;
    *bad_address = 1;

}

