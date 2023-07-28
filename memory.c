#include "Shell.h"


/**
 * bfree - free the pointer & NULLs the address
 * @ptr: free address of the pointer
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

