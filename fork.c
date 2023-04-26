#include <stdio.h>
#include <unistd.h>

int main(void)
{
  pid_t my_pid, pid;

  printf("Before Fork\n");

  pid = fork();

  if (pid == -1)
    {
      perror("Error: ");
      return (1);
    }

  my_pid = getpid();

  printf("After fork: \n");
  printf("My pid is %u\n", my_pid);

  return (0);
}
