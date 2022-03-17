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

    // Request a ton of memory
    for (int i = 0; i < 20970; i++) {

        p = mmap(NULL, 100000, PROT_NONE, MAP_ANON | MAP_PRIVATE | MAP_32BIT, -1, 0);

        if (p == MAP_FAILED) {
            perror("mmap");
            exit(1);
        }
    }

    printf("After mmap:\n");
    system(vmcmd);
    
    // Request one more mmap. Should put it in swap, but it is unclear after I tried
    // the last part
    printf("One more mmap but without `MAP_32BIT`\n");
    p = mmap(NULL, 100000, PROT_NONE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
	
    system(vmcmd);
 
    // Ask for one more mapping with MAP_32BIT
    printf("One more allocation in phys mem to show that physical memory is full\n");
    p = mmap(NULL, 100000, PROT_NONE, MAP_ANON | MAP_PRIVATE | MAP_32BIT, -1, 0);

    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }	
}

