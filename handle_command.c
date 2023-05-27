#include "main.h"

/**
 * check_and_execute - function that calls
 * other function to make command ready and execute it.
 *
 * @argv_buffer: buffer that save arguments.
 * @new_arg: full path command.
 *
 * Return: void.
 */
void check_and_execute(char *argv_buffer[], char *new_arg)
{
	built_in_command(argv_buffer);
	add_bin_prefix(argv_buffer, new_arg);
	create_process(argv_buffer);
}

/**
 * hundle_multi_command - function that handles
 * input command and spilt it executeble commands.
 *
 * @input_buffer: buffer that save input line.
 * @multi_command: buffer that save commands.
 *
 * Return: void.
 */
void hundle_multi_command(char *input_buffer, char *multi_command[])
{
	char *first_ptr = NULL;
	char *second_ptr = NULL;
	int argc = 0;
	int len;

	if (input_buffer != NULL)
	{
		len = _strlen(input_buffer);
		while (len > 0 && input_buffer[len - 1] == ' ')
			input_buffer[--len] = '\0';
	}
	first_ptr = input_buffer;
	while (*first_ptr && *first_ptr == ' ')
		first_ptr++;

	second_ptr = first_ptr;

	while (*first_ptr != '\0')
	{
		if (_strcmp(first_ptr, ";") == 0 || _strcmp(first_ptr, "\n") == 0
				|| _strcmp(first_ptr, "&&") == 0)
		{
			if (*first_ptr == '&')
			{
				*first_ptr = '\0';
				first_ptr++;
			}
			*first_ptr = '\0';
			while (*(first_ptr + 1) == ' ')
				first_ptr++;
			multi_command[argc++] = second_ptr;
			second_ptr = first_ptr + 1;
			if (argc >= MAXARGS)
				break;
		}
		first_ptr++;
	}
	multi_command[argc++] = second_ptr;
	multi_command[argc] = NULL;
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
