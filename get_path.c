#include "main.h"

/**
 * get_path - Retrieves and tokenizes the PATH environment variable.
 *
 * Return: NULL (currently prints PATH directories).
 *
 * Description: This function searches for the PATH environment variable,
 *              tokenizes it by '=' and ':', and prints each directory.
 */

char **get_path(void)
{

	int i = 0, j = 0;
	char *path_copy;
	char *token;
	char **tokens;
	char *delimiters = "=:";

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_copy = environ[i];
			break;
		}
		i++;
	}
	token = strtok(path_copy, delimiters);

	while (token != NULL)
	{

		token = strtok(NULL, delimiters);
		tokens[j] = token;
		printf("Dossier PATH : %s\n", tokens[j]);
		j++;
	}
	return (tokens);
}
