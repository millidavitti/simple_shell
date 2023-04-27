#include "main.h"
/**
 *store - stores split strings in an array
 *@string: string being split
 *@start: copy start
 *@end: copy end
 *@array: array to store split string
 *Return: void
 */
void store(char *string, int start, int end, char *array)
{
int i, j = 0;

for (i = start; i < end; i++, j++)
array[j] = string[i];
}
