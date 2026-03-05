#include <stdio.h>

/*
Roman numbers:
 I = 1,
 V = 5,
 X = 10,
 L = 50,
 C = 100,
 D = 500,
 M = 1000

 Rules: The same number cannot appear three times in a row.
*/

int validRomanNumber(char romanNumber[])
{
    int counter = 0;

    for (int i = 1; i < romanNumber[i] != '\0'; i++)
    {
        if (romanNumber[i] == romanNumber[i - 1])
        {
            counter++;
            if (counter >= 3)
            {
                printf("%s", "Invalid");
                return 0;
            }
        }
        else
        {
            counter = 0;
        }
    }
    printf("%s", "valid");
    return 1;
}

int main()
{
    validRomanNumber("XXXVVVIII");
    return 0;
}