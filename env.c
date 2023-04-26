#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **envp)
{
  char **env = environ;
  (void)ac, (void)av;
  int i;

  for (i = 0; env[i]; i++)
    printf("Env: %s\n",env[i]);

  printf("Environ Addy: %p\n", *env);
  printf("Envp Addy: %p\n", *envp);
  return (0);
}
