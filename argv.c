#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void store_string(char *line, char *chunk, int start, int end)
{
  int i, j;

  for (i = start, j = 0; i <= end; i++)
    {
      chunk[j] = line[i];
      j++;
    }
  chunk[j] = '\n';
}


char **_argv(char *line, char delimiter, int *count)
{
  int i, start = 0, j = 0;
  char **str_arr;
  
  str_arr = malloc(sizeof(str_arr) * 100);

  if (!str_arr)
    return (NULL);

  for (i = 0; i < 100; i++)
    str_arr[i] = malloc(sizeof *str_arr * 256);

  if (!str_arr)
    {
      free(str_arr);
	return (NULL);
    }

  for (i = 0; line[i]; i++)
    {
      if (line[i] == delimiter)
	{
	  store_string(line, str_arr[j], start, i);
	  start = i + 1;
	  j++;
	}
      else
	store_string(line, str_arr[j], start, i);
    }

  while(str_arr[*count][0])
    *count+=1;

  return (str_arr);
}

int main(void)
{
  char *lineptr;
  size_t n;
  char **strings;
  int i, c = 0;

  getline(&lineptr, &n, stdin);
  
  strings = _argv(lineptr, ' ', &c);
  printf("This is C: %d\n", c);

  for (i = 0; i < c - 1; i++)
    printf("%s", strings[i]);
  return (0);
}
