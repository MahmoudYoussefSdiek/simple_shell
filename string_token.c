#include "main.h"

/**
 * string_token - function that handles a string
 * (skip spaces and split it)
 *
 * @str: string we will handle.
 * @delimiter: character we will use to split string.
 * @argv: array that will save splitted string.
 *
 * Return: void.
 */
void string_token(char *str, char *delimiter, char *argv[])
{
	char *first_ptr = NULL;
	char *second_ptr = NULL;
	int argc = 0;

	if (str != NULL)
		first_ptr = str;

	while (*first_ptr && *first_ptr == ' ')
	{
		first_ptr++;
	}

	second_ptr = first_ptr;

	while (*first_ptr != '\0')
	{
		if (*first_ptr == *delimiter)
		{
			*first_ptr = '\0';
			while (*(first_ptr + 1) == ' ')
				first_ptr++;
			argv[argc++] = second_ptr;
			second_ptr = first_ptr + 1;
			if (argc >= MAX_INPUT_LENGTH)
				break;
		}
		first_ptr++;
	}
	argv[argc++] = second_ptr;
	argv[argc] = NULL;
}
