/*
**  file: fork04.c
**
**  Paulo Shirley @ UAb
**  v2008/03/20
*/

/**
 * While the parent process is sleeping, the child process remains
 * in a zombie state, waiting for the parent process to wake up and
 * complete its termination.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    printf("\nExample of application 04 of the fork() function\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Error in fork() function");
        exit(1);
    }

    if (pid)
    {
        /* pid>0, code for the parent process */
        printf("Parent Code  :  PID=%5d  PPID=%5d\n",
               (int)getpid(), (int)getppid());
        printf("Parent Code  :  Starting sleep(8)\n");
        sleep(8);
        printf("Parent Code  :  Finished sleep(8)\n");
    }
    else
    {
        /* pid=0, code for the child process */
        printf("Child Code:  PID=%5d  PPID=%5d\n",
               (int)getpid(), (int)getppid());
    }

    return 0;
}