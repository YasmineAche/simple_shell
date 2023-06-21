#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
  * path - fonctin that give the path
  *
  * @token: pointer to the token
  *
  * Return: string
  */
char *path(char *token)
{
	const char *str = "/bin/";
	int j = 0, i;
	char *result;

	if (token[0] == '/')
	{
		return (token);
	}
	else
	{
		while (token[j] != '\0')
		{
			j++;
		}
		result = malloc(sizeof(char) * (j + 6));
		if (result != NULL)
		{
			for (i = 0; i < 5; i++)
				result[i] = str[i];
			for (i = 5; i < 5 + j; i++)
				result[i] = token[i - 5];
			result[i] = '\0';
		}
	}
	return (result);
}
