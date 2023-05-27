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
