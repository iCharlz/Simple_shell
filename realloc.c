#include "shell.h"

/**
 * _memset - function that penetrates memory with a const byte
 * @i: Pointer to memory area
 * @j: byte to fill *i
 * @c: Bytes to be filled
 * Return: pointer to memory area (i)
 */
char *_memset(char *i, char j, unsigned int c)
{
	unsigned int n;

	for (n = 0; n < c; n++)
		i[n] = j;
	return (i);
}

/**
 * _realloc - function that reallocates block of memory
 * @ptr: The pointe to the previous mal;loc block
 * @old_size: The previous block byte size
 * @new_size: new block byte size
 * Return: The pointer to the old block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *n;

	if (!ptr)
	return (malloc(new_size));

	if (!new_size)
	return (free(ptr), NULL);

	if (new_size == old_size)
		return (ptr);

	n = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		n[old_size] = ((char *)ptr[old_size];
	free(ptr);
	return (n);
}

/**
 * ffree - Function that sets free a string of strings
 * @nn: The string of strings to free
 */

void ffree(char **nn)
{
	char **i == nn;

	if (!nn)
		return;
	while (*nn)
		free(*nn++);
	free(i);
}
