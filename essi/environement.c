#include "shell.h"
#include <stdio.h>
/**
  * print_env - prints environement
  *
  * Return: environement
  */
void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
