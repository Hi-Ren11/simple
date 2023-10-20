#include "gmama.h"

/**
 * print_ps1 - prints the primary shell prompt
 * @num: number that determines which errno value should be set
 */
void print_ps1(int num)
{
	const char *ps1 = "$ ";
	size_t len_ps1 = strlen(ps1);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, ps1, len_ps1);
	}

	errno = num == 0 ? 0 : errno;
}
