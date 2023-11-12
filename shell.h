#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DEL " \t\n"
extern char **environ;

char *read_commands(void);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

char **tokenizer(char *ligne);
int _execute(char **commands, char **av, int idx);

void freearray(char **a);
char *_getenv(char *var);
char *_getpath(char *cmd);
void printerr(char *name, char *md, int idx);
void reverse_str(char *str, int len);
char *_itoa(int n);

int fct_built(char *commande);
void hd_buil(char **commande, char **argv, int *status, int idx);
void exit_shell(char **commande, char **argv, int *status, int idx);
void print_env(char **commande, int *status);
int is_positive(char *str);
int _atoi(char *str);

void _puterror(char *r);
int print_setenv(char **commande);
int print_unsetenv(char **commande);
void command_cd(char **commande);
void _puts(char *str);


#endif
