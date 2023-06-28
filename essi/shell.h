#ifndef SHELL_H
#define SHELL_H

extern char **environ;

int _putchar(char c);
void print(void);
int _strcmp(char *s1, char *s2);
char *path(char *token);
void print_env(void);
void command(int num_tokens, char **args, char *programName);

#endif /* SHELL_H */
