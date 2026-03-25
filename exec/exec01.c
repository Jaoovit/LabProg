/*
**  file: exec01.c
**
**  Paulo Shirley @ UAb
**  v2008/03/24
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

    printf("\nExample application 01 of the fork()+exec() functions\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Error in fork() function");
        exit(1);
    }

    if (pid)
    {
        /* pid>0, code for the parent process */
        printf("Parent Code   :  PID=%5d  PPID=%5d\n",
               (int)getpid(), (int)getppid());
        printf("Parent Code   :  Starting wait()\n");
        pidw = wait(&status);
    }
    else
    {
        /* pid=0, code for the child process */
        printf("Child Code    :  Replace process image "
               "with the ls command and execute it!\n");
        execl("/bin/ls", "ls", "-al", NULL);
        printf("If this message appears, an error occurred!");
    }

    printf("Parent Code   :  ls -al command executed!\n");

    return 0;
}