#include "main.h"

/**
 * handle_env - prints the environment variables
 * @envp: Environment variables.
 *
 * Return: void
 */
void handle_env(char **envp)
{

	int i = 0;

	while (envp[i] != NULL)
	{
		write(STDOUT_FILENO, envp[i], strlen(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
