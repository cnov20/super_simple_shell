#include "shell.h"

/**
 * tokenizer - function that takes a given string and tokenizes it via delimiter
 * @str: string to be tokenized
 *
 * Return: array of tokens
 */

char **tokenizer (char *line)
{
        char **argv;
        char *token;
        char *line_copy;
        size_t i = 0;
        size_t word_count = 0;

	if (!line)
		return (NULL);

	line_copy = _strdup(line);
	token = strtok(line_copy, DELIMITER);

	while (token)
	{
		word_count++;
		token = strtok(NULL, DELIMITER);
	}

	token = strtok(line, DELIMITER);
	//Need to malloc +1 ??
	argv = malloc(sizeof(char *) * word_count);

	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, DELIMITER);
		i++;
	}

	argv[i] = NULL; /* set last element to null */
	free(line_copy);

	return (argv);
}
