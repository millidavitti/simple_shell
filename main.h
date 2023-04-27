#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

char **_strtok(char *string, char delimiter);
void store(char *string, int start, int end, char *array);
#endif /*MAIN_H*/
