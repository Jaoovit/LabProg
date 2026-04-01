#include "log.h"
#include <stdio.h>

int main()
{
    log_msg("message active works");
    log_error("error active works");
    log_active(0);
    log_msg("message active don't work");
    log_error("error active don't work");
    return 0;
}