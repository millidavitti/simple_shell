#include "main.h"

void store(char *string, int start, int end, char *array)
{
int i, j = 0;

for (i = start; i < end; i++, j++)
array[j] = string[i];
}
