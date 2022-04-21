/*
 * maximum-resident.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int
main(int argc, char *argv[])
{
    // Getting pid for procstat calls
    pid_t mypid;
    mypid = getpid();
    printf("my pid is %d\n", mypid);

    char vmcmd[32];
    snprintf(vmcmd, 32, "procstat vm %d", mypid);

    printf("Before mmap\n");
    system(vmcmd);

    char *p;
    p = mmap(NULL, 100000, PROT_WRITE, MAP_ANONYMOUS, -1, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Request a ton of memory
    for (int i = 0; i < 100000; i++) {
       *p = 'a';
       p++;
    }
    printf("After mmap:\n");
    system(vmcmd);
}

