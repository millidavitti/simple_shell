#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
  (void)argc;
  printf("Before  execve\n");

  if (execve(argv[0], argv, envp) == -1)
    {
      perror("Error: ");
    }

     printf("After execve\n");
    return (0);
}
