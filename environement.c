#include "shell.h"
#include <stdio.h>
/**
  * print_env - prints environement
  *
  * @token: 1st argument
  *
  * Return: environement
  */
void print_env(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
