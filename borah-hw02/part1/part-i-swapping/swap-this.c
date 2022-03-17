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
/*
    char *q = malloc(5);
    *q = 'g';
    for (int j = 0; j < INT_MAX; j++) {
        char *p = malloc(10000 * 10000);

        for (int i = 0; i < 10000; i++) {
            p[i * 100000] = 0;
        }
    }
    *q = 'a';
    pid_t mypid;
    mypid = getpid();
    kill(mypid, SIGKILL);
*/

/*
    char *p = mmap(NULL, INT_MAX, PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    *p = 'a';

    char *q = mmap(NULL, INT_MAX, PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    *q = 'b';

    *p = 'c';
*/

    char *d = mmap(NULL, INT_MAX, PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    *d = 'a';
    printf("here\n");
    char *p;
    for (int i = 0; i < INT_MAX; i++) {

        p = mmap(NULL, INT_MAX, PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

        if (p == MAP_FAILED) {
            perror("mmap");
            exit(1);
        }
	*p = 'a';
    }

    *d = 'k';
    free(d);

}
