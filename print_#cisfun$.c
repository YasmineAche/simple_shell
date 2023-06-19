#include "shell.h"
/**
  * print - fonction that print "#cisfun$ "
  *
  * Return: nothing
  */
void print(void)
{
	int i = 0;
	char *p = "#cisfun$ ";

	while (p[i] != '\0')
	{
		_putchar(p[i]);
		i++;
	}
}
