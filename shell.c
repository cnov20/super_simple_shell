#include "shell.h"

/**
 * main - function that takes in executable from command line and executes it
 *
 * Return: int - indicating success or failure
 */

int main(void)
{
	char **argv;
	char *line = NULL;
	size_t length = 0;
	ssize_t read;

	_putstring(PROMPT);
	while ((read = getline(&line, &length, stdin) != EOF))
	{
		if (_strcmp(line, "\n") == 0)
		{
			_putstring(PROMPT);
			continue;
		}
		if (!line)
		{
			_putstring("No line\n");
			_putstring(PROMPT);
		}

		argv = tokenizer(line);

		execute_cmd(argv);

		_putstring(PROMPT);
/*		free(line); */
/*		free(argv); */
	}
	return (EXIT_SUCCESS);
}
