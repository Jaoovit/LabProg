#include <stdio.h>
#include <string.h>

int checkIfIsPalindrome(char charArray[])
{
    char invertedArray[100] = {};
    int length = strlen(charArray);

    int pointer = 0;

    for (int i = length - 1; i > -1; i--)
    {
        invertedArray[i] = charArray[pointer];
        pointer++;
    }

    invertedArray[length] = '\0';

    if (strcmp(invertedArray, charArray) == 0)
    {
        return 1;
    }

    return 0;
}

int countPalindrome(FILE *textFile)
{
    if (textFile == NULL)
    {
        printf("File not found!");
        return 1;
    }

    char ch;
    int palindromes = 0;
    char currentWord[100] = {};
    int pointer = 0;

    while ((ch = fgetc(textFile)) != EOF)
    {
        if (ch == ' ' || ch == '.')
        {
            currentWord[pointer] = '\0';

            if (checkIfIsPalindrome(currentWord) && strlen(currentWord) > 2 && strlen(currentWord) < 11)
                palindromes++;

            pointer = 0;
        }
        else
        {
            currentWord[pointer++] = ch;
        }
    }

    currentWord[pointer] = '\0';
    if (checkIfIsPalindrome(currentWord) && strlen(currentWord) > 2 && strlen(currentWord) < 11)
        palindromes++;

    return palindromes;
}

int main()
{
    FILE *textFile = fopen("palindrome-text.txt", "r");
    printf("%i", countPalindrome(textFile));
    fclose(textFile);
    return 0;
}