/*
 * whither-mmap.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

void wait_for_input(void);

int
main(int argc, char *argv[])
{
    pid_t mypid;
    mypid = getpid();
    printf("my pid is %d\n", mypid);

    char vmcmd[32];
    snprintf(vmcmd, 32, "procstat vm %d", mypid);

    printf("Before mmap\n");
    system(vmcmd);
    wait_for_input();

    char *p = mmap(NULL, 10, PROT_NONE, MAP_ANONYMOUS, -1, 0);
    if(p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    printf("p address: %p\n", p); 

    printf("After mmap:\n");
    system(vmcmd);
}

void
wait_for_input(void)
{
    char buf[2];
    read(0, buf, 2);
}
