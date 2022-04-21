/*
 * maximum-resident.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <malloc_np.h>
#include <sys/types.h>
#include <signal.h>
#include <limits.h>

int
main(int argc, char *argv[])
{
    char *p = mmap(NULL, INT_MAX, PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Touch each byte in new mapping
    for (int i = 0; i < INT_MAX; i++) {
        *p = 'a';
        p++;
    }
    return 0;
}
