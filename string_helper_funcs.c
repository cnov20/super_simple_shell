#include "shell.h"

/**
 * *_strncat - concatenates two strings
 * @dest: string to be added to
 * @src: string to be appended
 * @n: max number of bytes allocated for src
 *
 * Return: pointer to dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{

	}

	for (j = 0; src[j] != '\0' && j < n; j++, i++)
	{
		dest[i] = src[j];
	}
	return (dest);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}

/**
 *
 *
 *
 */

void _putstring(char *str)
{
        unsigned int i;

        for (i = 0; str[i] != '\0'; i++)
        {
                _putchar(str[i]);
        }

}

/*void _putprompt(char *str)
{
	write(STDOUT_FILENO, str, _strlen(PROMPT));
}
*/

/**
 * *_memcpy - function that copies memory area
 * @dest: pointer to memory area s
 * @src: constant byte
 * @n: number of bytes of memory area pointed to by src
 *
 * Return: pointer to memory area (dest)
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
        unsigned int i;

        i = 0;
        while (i < n)
        {
                dest[i] = src[i];
                i++;
        }

        return (dest);
}

/**
 * _strcmp- compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: int equal to difference between characters
 */

int _strcmp(char *s1, char *s2)
{
        int i;

        i = 0;

        while (s1[i] == s2[i] && s1[i] != '\0')
        {
                i++;

        }
        if (s1[i] != s2[i])
        {
                return (s1[i] - s2[i]);
        }

        return (0);
}

/**
 * _strdup - function that allocates space for and creates copy of given string
 * @src: source string to be duplicated and memory allocated for
 *
 * Return: pointer to duplicated string
 */

char *_strdup(char *src)
{
        char *dup;
        size_t length;

        length = _strlen(src);
        dup = malloc(length);

        if (dup == NULL)
                return NULL;

        return(_memcpy(dup, src, length));
//	free(dup);
}

unsigned int _strlen(char *str)
{
        unsigned int i;

        for(i = 0; i != '\0'; i++)
        {
                _putchar(str[i]);
        }

        return (i);
}
