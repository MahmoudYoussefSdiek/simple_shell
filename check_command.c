#include "main.h"

/**
 * add_bin_prefix - function that adds full path to command.
 *
 * @argv: array of arguments.
 * @new_arg: full command.
 *
 * Return: void.
 */
void add_bin_prefix(char *argv[], char *new_arg)
{
	char *prefix_path = "/bin/";

	if (argv[0] == NULL)
		return;

	size_t prefix_len = strlen(prefix_path);
	size_t arg_len = strlen(argv[0]);

	if (strncmp(argv[0], prefix_path, prefix_len) == 0)
		return;

	strncpy(new_arg, prefix_path, prefix_len);
	strncpy(new_arg + prefix_len, argv[0], arg_len);
	new_arg[prefix_len + arg_len] = '\0';

	argv[0] = new_arg;
}
