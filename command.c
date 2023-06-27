#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/**
  * command - fonction
  *
  * @num_tokens: argument
  * @args: pointer to pointer
  * @programName: pointer
  */
void command(int num_tokens, char **args, char *programName)
{
	char *env[] = {NULL};
	pid_t pid;

	if ((_strcmp(args[0], "^C") == 0 || _strcmp(args[0], "exit") == 0))
	{
		if (num_tokens > 1)
		{
			exit(atoi(args[1]));
		}
		exit(0);
	}
	else if (_strcmp(args[0], "env") == 0 && (num_tokens == 1))
		print_env();
	else if (args[0] != NULL)
	{
		args[0] = path(args[0]);
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				perror(programName);
				exit(EXIT_FAILURE);
			}
		}
		else if (pid == -1)
			perror(programName);
		else
			wait(NULL);
	}
}
