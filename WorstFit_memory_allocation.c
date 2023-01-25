#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 100

int memory[MAX_MEMORY];

void worst_fit(int size)
{
    int i, worst_fit_index = -1, worst_fit_size = 0;
    for (i = 0; i < MAX_MEMORY;
