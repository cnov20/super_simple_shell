#include "shell.h"

int main(void)
{
	char *line = NULL;
        size_t length = 0;
        ssize_t read;
	pid_t pid;
	int status;
	char **argv;

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

		if (access(argv[0], X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(argv[0], argv, environ);
//				perror();
			}
			else if (pid < 0)
			{
				perror("Error\n");
				return (1);
			}
			else
			{
				wait(&status);
			}
		}
		_putstring(PROMPT);
//		free(line);
//		free(argv);
	}

	return (EXIT_SUCCESS);
}
