#include "main.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	char *lineprt = NULL;
	size_t n = 0;
	ssize_t r;

	while (1)
	{
		printf("$ ");
		r = getline(&lineprt, &n, stdin);
		if (r == -1)
		{
			printf("\n");
			break;
		}
		lineprt[r - 1] = '\0';
		printf("commande: %s\n", lineprt);
	}
	free(lineprt);
	return (0);
}
