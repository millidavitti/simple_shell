#include "main.h"

extern char **environ;
/**
 *main - entry point
 *Return: int
 */
int main(int argc, char **argv)
{
char *lineptr, **env = environ, delimiter = ' ', **av;
char *path = getenv("PATH"), *dir = strtok(path, ":"), filepath[256];
size_t n;
int i;
pid_t pid = -1;
(void)argc;

lineptr = malloc(sizeof(lineptr) * 256);
if (!lineptr)
return (1);

while (1)
{
printf("alx@shell$ ");

if (getline(&lineptr, &n, stdin) == -1)
{
/*Handle "end of file" condition*/
if (errno == EOF)
{
printf("\n");
break;
}
errno = 0; /* Reset errno to avoid endless loop */
break;
}

if (strcmp(lineptr, "exit\n") == 0)
break;
else if (strcmp(lineptr, "env\n") == 0)
{
for (env = environ; *env != NULL; env++)
printf("%s\n", *env);
continue;
}
av = _strtok(lineptr, delimiter);
for (i = 0; av[i][0]; i++)
;
av[i] = NULL;

if (!dir){
dir = strtok(path, ":");
}

while (dir)
{
sprintf(filepath, "%s/%s", "/usr/bin", av[0]);
if (access(filepath, X_OK) == 0)
/* Found the executable */
break;
dir = strtok(NULL, ":");
}
/*Swith between interactive an non-interactive*/
if (isatty(STDIN_FILENO))
{
/*interactive mode*/
if (access(filepath, X_OK) == 0)
pid = fork();
else
perror("./shell");
if (*(av[0]) != '/')
interact(pid, filepath, av, env);
else
interact(pid, av[0], av, env);
}
else
{
/*non-interactive mode*/
if (execve(av[0], av, env) == -1)
{
/*Handle error*/
printf("%s: %d: %s: not found\n",argv[0], argc, av[0]);
errno = 0;
break;
}
}
}
free(lineptr);
return (0);
}
