#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *palindromes[100] = {};
int palindromeCount = 0;

int storePalindromes(const char *palindrome)
{
    palindromes[palindromeCount] = malloc(strlen(palindrome) + 1);
    strcpy(palindromes[palindromeCount], palindrome);
    palindromeCount++;
    return 0;
}

int printPalindromes()
{
    for (int i = 0; i < palindromeCount; i++)
    {
        printf("%s\n", palindromes[i]);
    }
    return 0;
}

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

int findPalindrome(FILE *textFile)
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
        if (ch == ' ')
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
    FILE *textFile = fopen("phrase-palindrome-text.txt", "r");
    printPalindromes();
    fclose(textFile);
    return 0;
}