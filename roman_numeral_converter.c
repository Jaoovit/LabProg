#include <stdio.h>
#include <string.h>

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
    default:
        return 0;
    }
}

int validRomanNumber(char romanNumber[], int length)
{
    int counter = 0;

    for (int i = 1; i < length; i++)
    {
        if (romanNumber[i] != 'I' &&
            romanNumber[i] != 'V' &&
            romanNumber[i] != 'X' &&
            romanNumber[i] != 'L' &&
            romanNumber[i] != 'C' &&
            romanNumber[i] != 'D' &&
            romanNumber[i] != 'M')
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

int sumArrayContent(int arr[], int length)
{
    int arraySum = 0;

    for (int i = 0; i < length; i++)
    {
        arraySum += arr[i];
    }

    return arraySum;
}

int convertRomanNumber(char romanNumber[])
{
    int length = strlen(romanNumber);

    if (!validRomanNumber(romanNumber, length))
    {
        printf("%s", "Roman number invalid format");
        return 0;
    }

    int arr[10] = {0};

    for (int i = 0; i < length; i++)
    {
        if (decimalValue(romanNumber[i]) < decimalValue(romanNumber[i + 1]))
        {
            arr[i] = -decimalValue(romanNumber[i]);
        }
        else
        {
            arr[i] = decimalValue(romanNumber[i]);
        }
    }

    int romanNumberConverted = sumArrayContent(arr, length);
    return romanNumberConverted;
}

int main()
{
    printf("%i", convertRomanNumber("XIX"));
    return 0;
}