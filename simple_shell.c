#include "main.h"

/**
 * main - program that  Write a simple UNIX command interpreter.
 *
 * Return: 0.
 */
int main(void)
{
	pid_t id = 0;
	ssize_t bytes = 0;
	char input_buffer[MAX_INPUT_LENGTH];
	char new_arg[20];
	char *argv_buffer[MAXARGS];

	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode(bytes, id, input_buffer, argv_buffer, new_arg);
	}
	else
		non_interactive_mode(input_buffer, argv_buffer, new_arg);

	return (0);
}

/**
 * built_in_command - function that checks
 * if the command is a built-in command.
 *
 * @argv: array of arguments.
 * Return: 0 or 1.
 */
int built_in_command(char **argv)
{
	char **envp;
	int exit_status;

	if (_strcmp(argv[0], "exit") == 0)
	{
		exit_status = EXIT_SUCCESS;
		if (argv[1] != NULL)
		{
			exit_status = _atoi(argv[1]);
			if (exit_status < 0)
				exit(EXIT_FAILURE);
			 exit(exit_status);
		}
		exit(exit_status);
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		envp = environ;
		while (*envp != NULL)
		{
			write(STDOUT_FILENO, *envp, _strlen(*envp));
			write(STDOUT_FILENO, "\n", 1);
			envp++;
		}
		return (1);
	}
	return (0);
}
