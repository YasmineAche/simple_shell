#include "shell.h"
/**
  * _strcmp - compares two strings
  * @s1 : pointer to the variable
  * @s2 : pointer to the variable
  * Return: int
  */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*s1 != '\0' || *s2 != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0' && s2[i] == '\0')
		{
			break;
		}
		i++;
	}
	return (0);
}
