#ifndef MAIN_H
#define MAIN_H

#define MAX_INPUT_LENGTH 1024
#define MAXARGS 128

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>


void string_token(char *str, char *delimiter, char *argv[]);
void add_bin_prefix(char *argv[], char *new_arg);

void interactive_mode(int bytes, int id,
		char *input_buffer, char *argv_buffer[], char *new_arg);
void non_interactive_mode(char *input_buffer,
		char *argv_buffer[], char *new_arg);

int built_in_command(char **argv);

int _strlen(char *s);
void _strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);

#endif
