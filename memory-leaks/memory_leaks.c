#include <stdio.h>

void processDataWithMemoryLeak(int n)
{
    int *data = malloc(n * sizeof(n));

    if (data == NULL)
    {
        return; // withput alloc, no problem;
    }

    for (int i = 0; i < n; i++)
    {
        data[i] = i * 2;
    }

    if (n < 5)
    {
        return; // memory leak
    }

    free(data);
}