#include "shell.h"

/**
 * bfree - Frees pointer and NULLs thee address
 * @ptr: pointer to free
 * Return: 1 if free, othewrwise 0
 */

free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
