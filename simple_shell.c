#include "main.h"

/**
 * read_line - function that reads a line from file descriptor.
 *
 * @fd: file descriptor.
 * @input_buffer: buffer that save input line.
 *
 ' * Return: void.
 */
void read_line(int fd, char *input_buffer)
{
	int c;
	int i = 0;

	while (1)
	{
		c = read(fd, &input_buffer[i], 1);

		if (c == 0 || input_buffer[i] == '\n')
		{
			input_buffer[i] = '\0';
			break;
		}
		else
			i++;
	}
}

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
