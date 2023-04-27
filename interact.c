#include "main.h"

void interact(pid_t pid, char *filepath, char **av, char **env)
{
if (pid == -1)
{
/* Handle error */
perror("fork");
errno = 0;
}
else if (pid == 0)
{
/* Child process */
errno = 0;

if (execve(filepath, av, env) == -1)
{
/*Handle error*/
perror("./shell");
errno = 0;
}
exit(0); /* Exit child process */
}
else
{
/* Parent process */
wait(NULL); /* Wait for child process to finish */
}
}
