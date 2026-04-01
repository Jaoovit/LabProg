#include "log.h"
#include <stdio.h>

static int active = 1;

void log_active(int state)
{
    active = state;
}

void log_msg(const char *message)
{
    if (active == 1)
    {
        printf("%s\n", message);
    }
}

void log_error(const char *error)
{
    if (active == 1)
    {
        printf("[Error] %s\n", error);
    }
}