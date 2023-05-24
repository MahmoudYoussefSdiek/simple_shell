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

	bytes = read(STDIN_FILENO, input_buffer, MAX_INPUT_LENGTH);
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

/**
 * interactive_mode - function that handles
 * a command from interactive mode.
 *
 * @bytes: number of bytes from reading line.
 * @id: process id.
 * @input_buffer: buffer that save input line.
 * @argv_buffer: buffer that save arguments.
 * @new_arg: full path command.
 *
 * Return: void.
 */
void interactive_mode(int bytes, int id,
		char *input_buffer, char *argv_buffer[], char *new_arg)
{
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		bytes = read(STDIN_FILENO, input_buffer, MAX_INPUT_LENGTH);

		if (bytes == -1)
		{
			perror("Error reading from stdin");
			continue;
		}
		else if (bytes == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (input_buffer[bytes - 1] == '\n')
			input_buffer[bytes - 1] = '\0';

		string_token(input_buffer, " ", argv_buffer);
		add_bin_prefix(argv_buffer, new_arg);
		if (argv_buffer[0] == NULL)
			continue;

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
}
