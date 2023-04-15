#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   /* Added missing header for open() function */
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to standard output
 * @filename: pointer to the filename string
 * @letters: number of letters to read and print
 *
 * Return: the actual number of letters read and printed, 0 otherwise
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;  /* Changed type from ssize_t to int, as open() returns int */
	ssize_t let, w;
	char *text;

	if (filename == NULL)
		return (0);
	text = malloc(letters);
	if (text == NULL)
		return (0);
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		free(text);
		return (0);
	}
	let = read(file, text, letters);
	if (let == -1)
	{
		free(text);
		close(file);
		return (0);
	}
	w = write(STDOUT_FILENO, text, let);
	if (w == -1)
	{
		free(text);
		close(file);
		return (0);
	}
	free(text);
	close(file);
	return (w);
}

