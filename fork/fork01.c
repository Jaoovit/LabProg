/*
**  file: fork01.c
**
**  Paulo Shirley @ UAb
**  v2008/03/17
*/

/*
    The fork() function creates an exact copy of the calling process.
    It establishes a parent-child process relationship.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    printf("\nExample application 01 of the fork() function\n");
    printf("Parent process has PID=%5d\n", (int)getpid());
    pid = fork();
    if (pid == -1)
    {
        perror("Error in fork() function");
        exit(1);
    }
    if (pid)
    {
        /* pid>0, specific code for the parent process */
        printf("Parent Code:   Parent process has PID=%5d"
               " and the child has PID=%5d\n",
               (int)getpid(), (int)pid);
    }
    else
    {
        /* pid=0, specific code for the child process */
        printf("Child Code: Process parent has PID=%5d"
               " and the child has PID=%5d\n",
               (int)getppid(), (int)getpid());
    }

    /* pid irrelevant, code for both processes, parent and child */
    printf("*** End ***\n");
    return 0;
}