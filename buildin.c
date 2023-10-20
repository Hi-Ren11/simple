#include "gmama.h"
/**
 * run_build_in - checks if the the user calls a built-in cmd.
 * @ptrs: contains all the malloced spaces.
 * @filename: name of the file
 * Return: 1 for match not found, 0 for match found.
 */

int run_build_in(shell_t *ptrs, char *filename)
{
	size_t index;
	unsigned int num_words;
	char **input_words;
	built_t cmd[] = {
		{"exit", my_exit},
		{"env", print_env},
		{NULL, NULL},
	};

	(void)filename;
	if (!ptrs)
		return (1);
	if (!(ptrs->input_token[0]))
		return (1);

	input_words = ptrs->input_token;
	num_words = 0;
	while (input_words[num_words] != NULL)
		num_words++;
	index = 0;
	while (cmd[index].cmd_name)
	{
		if (!_strcmp(ptrs->input_token[0], cmd[index].cmd_name))
		{
			(cmd[index].cmd)(ptrs);
			return (0);
		}
		index++;
	}
	return (1);
}
