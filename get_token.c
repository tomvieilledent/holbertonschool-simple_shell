#include "main.h"

/**
 * splitCommand - Splits a string into tokens based on delimiters.
 * @input: Pointer to the input string to be tokenized.
 * @argv: Array to store the tokens.
 *
 * Return: The number of tokens found.
 *
 * Description: This function takes an input string and splits it into tokens
 *              using space, tab, and newline as delimiters. It stores each
 *              token in the argv array. The caller is responsible for ensuring
 *              the input and argv are not NULL.
 */

int splitCommand(char *input, char **argv)
{
	int count = 0;
	int max_tokens = 128;
	char *delimiters = " \n\t";
	char *token;

	if (input == NULL || argv == NULL)
		return (0);

	token = strtok(input, delimiters);

	while (token != NULL && count < max_tokens - 1)
	{
		argv[count++] = token;
		token = strtok(NULL, delimiters);
	}

	argv[count] = NULL;
	return (count);
}
