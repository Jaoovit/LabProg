#include "student.h"

int counter = 0;
float sum = 0;

void add_value(float v)
{
    counter++;
    sum += v;
}

float calculate_media()
{
    return sum / counter;
}