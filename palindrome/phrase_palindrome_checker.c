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

char *clearString(const char *input)
{
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
        return 1;
    char ch;
    char currentPhrase[200] = {};
    int pointer = 0;
    while ((ch = fgetc(textFile)) != EOF)
    {
        if (ch == '.' || ch == '?' || ch == '!' || ch == ',' || ch == ';' || ch == ':')
        {
            currentPhrase[pointer] = '\0';
            if (strlen(currentPhrase) > 0 && checkIfIsPalindrome(currentPhrase))
                storePalindromes(currentPhrase);
            pointer = 0;
        }
        else
        {
            currentPhrase[pointer++] = ch;
        }
    }
    currentPhrase[pointer] = '\0';
    if (strlen(currentPhrase) > 0 && checkIfIsPalindrome(currentPhrase))
        storePalindromes(currentPhrase);
    return 0;
}

int main()
{
    FILE *textFile = fopen("phrase-palindrome-text.txt", "r");
    if (textFile == NULL)
        return 0;
    findPalindrome(textFile);
    printPalindromes();
    fclose(textFile);
    return 0;
}