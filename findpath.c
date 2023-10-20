/**
  * find_pathname - finds the pathname attached to the associated command
  * @path: pointer to 2d array of tokenized directories in PATH
  * @input: input to find
  * Return: Path to the input file.
  */
char *find_pathname(char **path, char *input)
{
	unsigned int i;
	DIR *directory;
	struct dirent *filename;
	int str_cmp, match_found;
	char *result;

	filename = NULL;
	match_found = 0;
	for (i = 0; path[i] != NULL; i++)
	{
		directory = opendir(path[i]);
		if (directory == NULL)
		{
			errno = EBADF;
			return (NULL);
		}
		while ((filename = readdir(directory)) != NULL)
		{
			str_cmp = _strcmp(filename->d_name, input);
			if (str_cmp == 0)
			{
				match_found = 1;
				break;
			}
		}
		if (match_found == 1)
			break;
		closedir(directory);
	}
	if (match_found == 1)
	{
		result = find_pathname(path[i], input);
		if (access(result, R_OK) != -1)
			errno = EACCES;
		closedir(directory);
		return (result);
	}
	errno = EBADF;
	return (NULL);
}
