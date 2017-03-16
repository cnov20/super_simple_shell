#include "shell.h"

/**
 * execute_cmd - function forks child process, if command is executable
 * @argv: double pointer to argument vector(value)
 *
 * Return: integer value of pid to calling function
 */

int execute_cmd(char **argv)
{
	pid_t pid;
	int status;

	if (access(argv[0], X_OK) == 0)
	{
		pid = fork();

		if (pid == 0)
		{
			execve(argv[0], argv, environ);
			/*	perror(); */
		}
		else if (pid < 0)
		{
			perror("Error\n");
			return (1);
		}
		else
			wait(&status);
	}

	return (pid);
}
