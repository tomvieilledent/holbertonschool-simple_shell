#include "main.h"

/**
 * main - Entry point for the simple shell program.
 * @argc: Argument count (unused).
 * @argv: Argument vector (unused).
 * @envp: Environment variables.
 *
 * Return: 0 on success, or another value on error.
 */
int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t r;

	(void)argc;
	(void)argv;
	int last_status = 0;
	int ret;

	signal(SIGINT, handle_sigint);

	while (1)
	{
		display_prompt();

		r = read_line(&line, &n);
		if (r == -1)
			break;

		if (clean_line(line, r) == 0)
			continue;

		execute_command(line, envp);
		ret = execute_command(line);
		if (ret == -1)
		{
			free(line);
			return (last_status);
		}
		last_status = ret;
	}

	free(line);
	return (last_status);
}
