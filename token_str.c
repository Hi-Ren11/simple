#include "gmama.h"

/**
 * tokenize_str - Tokenize a string using a specified delimiter.
 * @str: The string to be tokenized.
 * @delim: The delimiter used for tokenization.
 *
 * Return: An array of tokens (strings) or NULL on failure.
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
		tokens[n_delim] = _strdup(tok);
		tok = _strtok(NULL, delim);
		n_delim++;
	}
	tokens[n_delim] = NULL;

	return (tokens);
}

