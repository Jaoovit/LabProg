/*
**  file: cmd01.c
**
**  Paulo Shirley @ UAb
**  v2009/03/12
*/

/*
    The output of the line `char cmd[] = "ps -f"` is a process tree:
    PID: Process identifier
    PPID: Parent process ID
    CMD: Associated command/program of the process

    The shell (bash) creates the `cmd01` program process. `cmd01` calls `system("ps -f")`,
    which creates a new `sh` process (command interpreter). This `sh` process then creates
    the `ps` process to execute the requested command.

    --------------------------------------------------------------------------------

    The output of the line `char cmd[] = "ps -o pid,ppid,user,state,time,comm"`
    is also a list of processes.

    S: State of the process
        R: Running/Runnable
        S: Sleeping
    TIME: Total accumulated CPU time used
    COMMAND: Short name of the command
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* char cmd[] = "ps -f"; */
    char cmd[] = "ps -o pid,ppid,user,state,time,comm";

    printf("\nExecuting the command \"%s\"\n", cmd);
    system(cmd);
    printf("*** End ***\n");
    return 0;
}