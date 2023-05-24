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
