#include "main.h"

extern char **environ;

int main (void)
{
char *lineptr, **env = environ, delimiter = ' ', **av;
size_t n;
int i;
pid_t pid;
char *path = getenv("PATH");
char *dir = strtok(path, ":");
char filepath[256];

lineptr = malloc(sizeof(lineptr) * 256);

if (!lineptr)
return (1);


while (1) {
printf("alx@shell$ ");

if (getline(&lineptr, &n, stdin) == -1) 
{

/*Handle "end of file" condition*/
if (errno == EOF) {
printf("\n");
break;
}

/* Handle other errors */
perror(NULL);
errno = 0; /* Reset errno to avoid endless loop */
break;
}

if (strcmp(lineptr, "exit\n") == 0) {
break;
}
else if (strcmp(lineptr, "env\n") == 0) {

for (env = environ; *env != NULL; env++) {
printf("%s\n", *env);
}
continue;
}

av = _strtok(lineptr, delimiter);
for (i = 0; av[i][0]; i++)
;
av[i] = NULL;

while (dir) {
sprintf(filepath, "%s/%s", dir, av[0]);
if (access(filepath, X_OK) == 0)
/* Found the executable */
break;
dir = strtok(NULL, ":");

}
if (isatty(STDIN_FILENO)) {
/*interactive mode*/
/*Execute the command*/
pid = fork();
if (pid == -1) {
/* Handle error */
perror("fork");
errno = 0;
} 
else if (pid == 0) {
/* Child process */
errno = 0;

if (execve(filepath, av, env) == -1) {
/*Handle error*/
perror("./shell");
errno = 0;
}
exit(0); /* Exit child process */
} else {
/* Parent process */
wait(NULL); /* Wait for child process to finish */
}
} else {
/*non-interactive mode*/
if (execve(av[0], av, env) == -1) {
/*Handle error*/
perror("./shell");
errno = 0;
}
}
}

free(lineptr);

return (0);
}
