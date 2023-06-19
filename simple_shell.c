#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
  * main - main entry point
  * Return: int
  */
int main(void)
{
	int flag = 1;
	char *line = NULL, *token, *delimiter = " \t\n";
	size_t buffsize = 0;
	ssize_t nbr_read_char;
	char *args[] = {NULL, NULL}, *env[] = {NULL};

	while (flag == 1)
	{
		print();
		free(line);
		line = NULL;
		nbr_read_char = getline(&line, &buffsize, stdin);
		if (nbr_read_char == -1 && feof(stdin))
		{
			perror("Error reading input");
			break;
		}
		token = strtok(line, delimiter);
		while (token != NULL)
		{
			if (_strcmp(token, "^C") == 0 || _strcmp(token, "exit") == 0)
			{
				flag = 0;
			}
			else if (_strcmp(token, "ls") == 0)
			{
				if (fork() == 0)
				{
					execve(args[0], args, env);
					perror(args[0]);
					exit(EXIT_FAILURE);
				}
				else
				{
					wait(NULL);
				}
			}
			token = strtok(NULL, delimiter);
		}
	}
	free(line);
	return (0);
}
