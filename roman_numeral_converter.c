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

    int decimalNumber = 0;

    for (int i = 1; i < romanNumber[i] != '\0'; i++)
    {
        if (romanNumber[i] != "I" ||
            romanNumber[i] != "V" ||
            romanNumber[i] != "X" ||
            romanNumber[i] != "L" ||
            romanNumber[i] != "C" ||
            romanNumber[i] != "D" ||
            romanNumber[i] != "M")
        {
            return 0;
        }

        if (romanNumber[i] == romanNumber[i - 1])
        {
            counter++;
            if (counter >= 3)
            {
                return 0;
            }
        }
        else
        {
            counter = 0;
        }
    }
    return 1;
}

int decimalValue(char unit)
{
    switch (unit)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
}

int convertRomanNumber(char romanNumber[])
{
    if (!validRomanNumber(romanNumber))
    {
        printf("%s", "Roman number invalid format");
        return 0;
    }

    for (int i = 0; i < romanNumber[i] != '\0'; i++)
    {
    }
}

int main()
{
    convertRomanNumber("XXXVVVVIII");
    return 0;
}