#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 100

int memory[MAX_MEMORY];

void first_fit(int size)
{
    int i;
    for (i = 0; i < MAX_MEMORY; i++)
    {
        if (memory[i] == 0)
        {
            int j, flag = 1;
            for (j = i; j < i + size; j++)
            {
                if (memory[j] != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                for (j = i; j < i + size; j++)
                    memory[j] = 1;
                printf("Allocated memory using First-Fit at index %d of size %d\n", i, size);
                return;
            }
        }
    }
    printf("Error: Not enough memory available using First-Fit\n");
}
