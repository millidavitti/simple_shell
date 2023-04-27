#include "main.h"
/**
 *_strtok - splits string by its delimiter
 *@string: string to split
 *@delimiter: delimiter
 *Return: array of strings
 */
char **_strtok(char *string, char delimiter)
{
int i, start = 0, j = 0;
char **str_arr;

str_arr = malloc(sizeof(str_arr) * 1024);

if (!str_arr)
return (NULL);

for (i = 0; i < 1024; i++)
str_arr[i] = malloc(sizeof(*str_arr[i]) * 256);

if (!str_arr)
{
free(str_arr);
return (NULL);
}

for (i = 0; string[i]; i++)
{
if (string[i] == delimiter)
{
store(string, start, i, str_arr[j]);
start = i + 1;
j++;
}
else
store(string, start, i, str_arr[j]);
}
return (str_arr);
}
