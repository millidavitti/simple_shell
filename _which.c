#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int ac, char **av)
{
   char* path = getenv("PATH");
  int i;
  struct stat st;
  
  if (ac < 2)
    return (1);

  i = 1;

  while(av[i])
    {

  if (stat(path, &st) == 0)
    printf("File: %s is in the current directory\n", av[i]);
  else
    printf("File: %s not found in the current directory\n", av[i]);
  i++;
  }
  return (0);
}
