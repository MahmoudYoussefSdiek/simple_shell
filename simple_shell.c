#include "main.h"

/**
 * main - program that  Write a simple UNIX command interpreter.
 *
 * Return: 0.
 */
int main(void)
{
	pid_t id;
	ssize_t bytes = 0;
	char input_buffer[MAX_INPUT_LENGTH];
	char new_arg[20];
	char *argv[MAXARGS];

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
			write(STDOUT_FILENO, "EOF received, exiting...\n", 25);
			break;
		}
		if (input_buffer[bytes - 1] == '\n')
			input_buffer[bytes - 1] = '\0';

		string_token(input_buffer, " ", argv);
		add_bin_prefix(argv, new_arg);
		if (argv[0] == NULL)
			continue;

		id = fork();
		if (id == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (id == 0)
		{
			execve(argv[0], argv, NULL);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}

	return (0);
}
