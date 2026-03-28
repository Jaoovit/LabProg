#include "student.h"
#include <stdio.h>

int main()
{
    add_value(10.5);
    add_value(20.0);
    printf("Media: %2.f\n", calculate_media());
    return 0;
}