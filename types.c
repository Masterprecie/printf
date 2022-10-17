#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * format_s - specificer s
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_s(va_list valist, char *buffer, int *index)
{
	int i, j;
	char *s;

	s = va_arg(valist, char *);
	if (s == NULL)
		s = "(null)";
	for (i = *index, j = 0; s[j] != '\0'; *index += 1, i++, j++)
	{
		if (*index == 1024)
		{
			_write_buffer(buffer, index);
			reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = s[j];
	}
}
/**
 * format_c - specificer c
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_c(va_list valist, char *buffer, int *index)
{
	char s;

	s = va_arg(valist, int);
	if (*index == 1024)
	{
		_write_buffer(buffer, index);
		reset_buffer(buffer);
		*index = 0;
	}
	buffer[*index] = s;
	*index += 1;
}

/**
 * format_d - function that returns an int to signed decimal
 * @valist: arguments passed
 * @buffer: values stored
 * @index: tracks index position
 */
void format_d(va_list valist, char *buffer, int *index)
{
	int i, j, numlen;
	char *num_str;

	i = va_arg(valist, int);

	numlen = num_len(i);
	if (i < 0)
	{
		numlen += 1;
	}
	num_str = malloc(numlen * sizeof(char));
	if (num_str == NULL)
		return;
	itos(num_str, i);
	for (i = *index, j = 0; j < numlen; *index += 1, i++, j++)
	{
		if (*index == 1024)
		{
			_write_buffer(buffer, index);
			reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = num_str[j];
	}
	free(num_str);
}
/**
 * format_perc - percent
 * @valist: valist
 * @buffer: write to buffer
 * @index: the index
 * Return: void
 */
void format_perc(
	 __attribute__((unused)) va_list valist, char *buffer, int *index)
{
	buffer[*index] = '%';
	*index += 1;
}

/**
 * format_R - functtion that converts a string into rot13
 * @valist: argument passed
 * @buffer: values stored
 * @index: tracks index position
 */
void format_R(va_list valist, char *buffer, int *index)
{
	char *s;
	int i, j;

	char *s1 = "abcdefghijklmABCDEFGHIJKLM ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";
	char *s2 = "nopqrstuvwxyzNOPQRSTUVWXYZ ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";

	s = va_arg(valist, char *);
	for (i = 0; s[i] != '\0'; i++, *index += 1)
	{
		for (j = 0; s1[j] != '\0'; j++)
		{
			if (s[i] == s1[j])
			{
				buffer[*index] = s2[j];
			}
			else if (s[i] == s2[j])
			{
				buffer[*index] = s1[j];
			}
		}
	}
}
