#include <stdio.h>

int validRomanNumber(char romanNumber[])
{
    return 0;
}

char romanNumber[] = "XXX";

int main()
{

    int romanNumberSize = sizeof(romanNumber);

    for (int i = 0; i < romanNumberSize; i++)
    {
        printf("%c", romanNumber[i]);
    }

    return 0;
}