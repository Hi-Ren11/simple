#include "gmama.h"

/**
 * tokenize_str - function that take a string split them up at a delimiters and
 * add them into a array.
 * @str: string to process.
 * @delim: delimiter to split at.
 *
 * Return: pointer to pointers
 */

char **tokenize_str(char *str, char *delim)
{
	size_t n_delim = 0;
	char *str_dup, *tok;
	char **tokens;

	if (!str || !delim)
		return (NULL);
	str_dup = _strdup(str);

	tok = _strtok(str_dup, delim);
	while (tok)
	{
		n_delim++;
		tok = _strtok(NULL, delim);
	}
	free(str_dup);
	tokens = malloc(sizeof(char *) * (n_delim + 1));
	if (!tokens)
		return (NULL);

	tok = _strtok(str, delim);
	n_delim = 0;
	while (tok)
	{
		tokens[n_delim] = tok;
		tok = _strtok(NULL, delim);
		n_delim++;
	}
	tokens[n_delim] = NULL;

	return (tokens);
}
