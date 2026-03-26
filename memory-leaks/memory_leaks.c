#include <stdio.h>

void processDataWithMemoryLeak(int n)
{
    int *data = malloc(n * sizeof(n));

    if (data == NULL)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        data[i] = i * 2;
    }

    if (n < 5)
    {
        return;
    }

    free(data);
}

void processDataWithoutMemoryLeak(int n)
{
    int *data = malloc(n * sizeof(n));

    if (data == NULL)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        data[i] = i * 2;
    }

    if (n < 5)
    {
        free(data);
        data = NULL;
        return;
    }

    free(data);
    data = NULL;
}