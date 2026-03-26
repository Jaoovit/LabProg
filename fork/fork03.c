/*
**  file: fork03.c
**
**  Paulo Shirley @ UAb
**  v2008/03/17
*/

/**
 * If a parent process terminates before its child process,
 * the operating system automatically reassigns the child
 * to a new parent process.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    printf("\nExample of application 03 of the fork() function\n");
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
    }
    else
    {
        /* pid=0, code for the child process */
        printf("Child Code:  PID=%5d  PPID=%5d\n",
               (int)getpid(), (int)getppid());
        printf("Child Code:  Starting sleep(3)\n");
        sleep(3);
        printf("Child Code:  Finished sleep(3)\n");
        printf("Child Code:  PID=%5d  PPID=%5d\n",
               (int)getpid(), (int)getppid());
    }

    return 0;
}