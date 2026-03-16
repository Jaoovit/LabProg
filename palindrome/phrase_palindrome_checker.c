#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    char *finalArray = malloc(strlen(input) + 1);
    int i = 0, pointer = 0;

    while (input[i] != '\0')
    {
        unsigned char c = input[i];

        if (c < 128)
        {
            if (c != ' ' && c != '-')
                finalArray[pointer++] = tolower(c);
            i++;
        }
        else
        {
            unsigned char next = input[i + 1];

            if (c == 0xC3)
            {
                switch (next)
                {
                case 0xA1:
                case 0xA0:
                case 0xA3:
                case 0xA2:
                case 0xA4:
                    finalArray[pointer++] = 'a';
                    break;

                case 0xA9:
                case 0xA8:
                case 0xAA:
                case 0xAB:
                    finalArray[pointer++] = 'e';
                    break;

                case 0xAD:
                case 0xAC:
                case 0xAE:
                case 0xAF:
                    finalArray[pointer++] = 'i';
                    break;

                case 0xB3:
                case 0xB2:
                case 0xB5:
                case 0xB4:
                case 0xB6:
                    finalArray[pointer++] = 'o';
                    break;

                case 0xBA:
                case 0xB9:
                case 0xBB:
                case 0xBC:
                    finalArray[pointer++] = 'u';
                    break;

                case 0xA7:
                    finalArray[pointer++] = 'c';
                    break;
                }
            }

            i += 2;
        }
    }

    finalArray[pointer] = '\0';
    return finalArray;
}

int checkIfIsPalindrome(char charArray[])
{
    char *clean = clearString(charArray);

    int length = strlen(clean);
    char invertedArray[200];

    for (int i = 0; i < length; i++)
    {
        invertedArray[i] = clean[length - 1 - i];
    }

    invertedArray[length] = '\0';

    int result = strcmp(invertedArray, clean) == 0;

    free(clean);

    return result;
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
    for (int i = 0; i < palindromeCount; i++)
    {
        free(palindromes[i]);
    }
    return 0;
}