#include "gmama.h"

/**
  * make_pathname - takes result from path_name and creates a string.
  * string contains the full pathname.
  * @path: pathname
  * @file: file in the path
  * Return: pointer to an allocated string that contains the full pathname.
  */
char *make_pathname(char *path, char *file)
{
	size_t num_path, num_file;
	char *result;
	unsigned int j, k;

	num_path = _strlen(path);
	num_file = _strlen(file);
	result = malloc(sizeof(char) * (num_path + num_file + 2));
	if (result == NULL)
		return (NULL);
	for (j = 0; j < num_path; j++)
		result[j] = path[j];
	result[j++] = '/';
	for (k = 0; k < num_file; k++)
		result[j + k] = file[k];
	result[j + k] = '\0';
	return (result);
}
