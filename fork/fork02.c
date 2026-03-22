/*
**  file: fork02.c
**
**  Paulo Shirley @ UAb
**  v2008/03/17
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define NITER 2

int main()
{
    pid_t pid;
    int i;

    printf("\nExample application 02 of the fork() function\n");
    printf("Initial parent process has PID=%5d\n", (int)getpid());
    for (i = 1; i <= NITER; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("Error in fork() function");
            exit(1);
        }
        if (pid)
        {
            /* pid>0, code for the parent process */
            printf("Parent Code  (i=%2d):  PID=%5d  PPID=%5d\n",
                   i, (int)getpid(), (int)getppid());
        }
        else
        {
            /* pid=0, code for the child process */
            printf("Child Code (i=%2d):  PID=%5d  PPID=%5d\n",
                   i, (int)getpid(), (int)getppid());
        }
    }
    return 0;
}