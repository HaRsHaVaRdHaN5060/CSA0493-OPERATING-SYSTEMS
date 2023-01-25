#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 100

int memory[MAX_MEMORY];

void best_fit(int size)
{
    int i, best_fit_index = -1, best_fit_size = MAX_MEMORY;
    for (i = 0; i < MAX_MEMORY; i++)
    {
        if (memory[i] == 0)
        {
            int j, flag = 1, temp_size = 0;
            for (j = i; j < MAX_MEMORY; j++)
            {
                if (memory[j] != 0)
                {
                    flag = 0;
                    break;
                }
                temp_size++;
            }
            if (flag && temp_size >= size && temp_size < best_fit_size)
            {
                best_fit_index = i;
                best_fit_size = temp_size;
            }
        }
    }
    if (best_fit_index != -1)
    {
        for (i = best_fit_index; i < best_fit_index + size; i++)
            memory[i] = 1;
        printf("Allocated memory using Best-Fit at index %d of size %d\n", best_fit_index, size);
    }
    else
        printf("Error: Not enough memory available using Best-Fit\n");
}
