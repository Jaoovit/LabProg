/*
**  file: fork05.c
**
**  Paulo Shirley @ UAb
**  v2008/03/20
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid, pidw;
    int status;

    printf("\nExample of application 05 of the fork() function\n");
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
        printf("Parent Code  :  Starting wait()\n");
        pidw = wait(&status);
        printf("Parent Code  :  Child process PID=%5d terminated!\n",
               (int)pidw);
    }
    else
    {
        /* pid=0, code for the child process */
        printf("Child Code:  PID=%5d  PPID=%5d\n",
               (int)getpid(), (int)getppid());
        printf("Child Code:  Starting sleep(8)\n");
        sleep(8);
        printf("Child Code:  Finished sleep(8)\n");
        printf("Child Code:  PID=%5d  PPID=%5d\n",
               (int)getpid(), (int)getppid());
    }

    return 0;
}