#include "main.h"

/**
 * main - program that  Write a simple UNIX command interpreter.
 *
 * Return: 0.
 */
int main(void)
{
	ssize_t bytes = 0;
	char input_buffer[MAX_INPUT_LENGTH];
	char new_arg[20];
	char *multi_command[MAXARGS];
	char *argv_buffer[MAXARGS];

	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode(bytes, input_buffer, argv_buffer, new_arg);
	}
	else
		non_interactive_mode(input_buffer, multi_command, argv_buffer, new_arg);

	return (0);
}
