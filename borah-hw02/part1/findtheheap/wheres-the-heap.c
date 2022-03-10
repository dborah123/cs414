/*
 * wheres-the-heap.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void wait_for_input(void);

int
main(int argc, char *argv[])
{
    pid_t mypid;
    mypid = getpid();
    printf("my pid is %d\n", mypid);

    char vmcmd[32];
    snprintf(vmcmd, 32, "procstat vm %d", mypid);

    printf("Before malloc:\n");
    system(vmcmd);
    wait_for_input();

    char *p = malloc(1024);
    if(p == NULL) {
        perror("malloc");
        exit(1);
    }

    printf("After malloc:\n");
    system(vmcmd);
    wait_for_input();

    free(p);
    printf("After free:\n");
    system(vmcmd);
}

void
wait_for_input(void)
{
    char buf[2];
    read(0, buf, 2);
}
