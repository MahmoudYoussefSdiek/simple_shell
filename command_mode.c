#include "main.h"

/**
 * non_interactive_mode - function that handles
 * a command from non interactive mode.
 *
 * @input_buffer: buffer that save input line.
 * @argv_buffer: buffer that save arguments.
 * @new_arg: full path command.
 *
 * Return: void.
 */
void non_interactive_mode(char *input_buffer,
		char *argv_buffer[], char *new_arg)
{
	int id;
	int bytes;

	read_line(STDIN_FILENO, input_buffer);
	bytes = _strlen(input_buffer);
	if (input_buffer[bytes - 1] == '\n')
		input_buffer[bytes - 1] = '\0';

	string_token(input_buffer, " ", argv_buffer);
	add_bin_prefix(argv_buffer, new_arg);

	id = fork();
	if (id == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (id == 0)
	{
		execve(argv_buffer[0], argv_buffer, NULL);
		perror(argv_buffer[0]);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
