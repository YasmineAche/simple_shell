#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 100

/**
  * main - shell prompt program
  * @argc: variable not used
  * @argv: pointer to a list (used to get the name of the file)
  * Return: int
  */
int main(int argc, char *argv[])
{
	int flag = 1, num_tokens = 0;
	char *line = NULL, *token;
	size_t buffsize = 0;
	ssize_t nbr_read_char;
	char *args[MAX_ARGS + 1], *env[] = {NULL}, *programName = argv[0];
	pid_t pid;

	(void)argc;
	while (flag == 1)
	{
		if (isatty(STDIN_FILENO))
			print();
		nbr_read_char = getline(&line, &buffsize, stdin);
		if (nbr_read_char == -1 && feof(stdin))
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		token = strtok(line, " \t\n");
		while (token != NULL && num_tokens < MAX_ARGS)
		{
			if (*token != '\0')
			{
				args[num_tokens] = token;
				num_tokens++;
			}
			token = strtok(NULL, " \t\n");
		}
		args[num_tokens] = NULL;
		if (num_tokens > 0)
		{
			if ((_strcmp(args[0], "^C") == 0 || _strcmp(args[0], "exit") == 0) && (num_tokens == 1))
				flag = 0;
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
		num_tokens = 0;
	}
	free(line);
	return (0);
}
