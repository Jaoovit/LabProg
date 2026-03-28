#include <stdio.h>
#include "geometry.h"

/** Function to calculate circle area */
double circleArea(double radius)
{
    double pi = 3.14159;
    return pi * radius * radius;
}

/** Function to calculate rectangle area */
double rectangleArea(double base, double height)
{
    return base * height;
}

int main()
{
    printf("Circle area: %.2f\n", circleArea(5));
    printf("Rectangle area: %.2f\n", rectangleArea(3, 4));
    return 0;
}
