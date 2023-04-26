#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void store(char *string, char *arr, int start, int end) {
int i, j;

for (i = start, j = 0; i < end; i++,j++)
arr[j] = string[i];
arr[j] = '\0';

}

char **_strtok(char *string, char delimiter)
{
char **key,**value;
int i, start = 0, j = 0;

key = malloc(sizeof(key) * 10);
value = malloc(sizeof(key) * 10);

if (!key|| !value )
return (NULL);

for (i = 0; i < 10; i++)
{
key[i] = malloc(sizeof(*key) * 256);
value[i] = malloc(sizeof(*key) * 256);
}

if (!key || !value)
{
free(key);
free(value);
return (NULL);
}

for (i = 0; string[i]; i++)
{
if (string[i] == delimiter)
{
store(string, key[j], start, i);
start = i + 1;
store(string, value[j], start, strlen(string));
j++;
}

}
for (i = 0; key[i]; i++)
printf("Keys: %s\n", key[i]);
for (i = 0; value[i]; i++)
printf("Values: %s\n", value[i]);
return (value);
}

