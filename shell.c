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
	int num_tokens = 0;
	char *line = NULL, *token;
	size_t buffsize = 0;
	ssize_t nbr_read_char;
	char *args[MAX_ARGS + 1], *programName = argv[0];

	(void)argc;
	while (1)
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
			command(num_tokens, args, programName);
		}
		num_tokens = 0;
	}
	free(line);
	return (0);
}
