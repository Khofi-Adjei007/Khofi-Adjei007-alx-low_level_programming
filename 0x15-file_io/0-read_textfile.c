#include "main.h"

/**
* read_textfile - reads a text file and
* prints its contents to stdout
* @filename: the name of the file to read
* @letters: the number of letters to read and print
*
* Return: If the function succeeds,
* it returns the actual number of letters read
* and printed. If filename is NULL or if the file
* cannot be opened or read, or if
* write fails or returns an unexpected number of bytes,
* the function returns 0.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer = NULL;
/* pointer to the buffer thatwill hold file contents */

ssize_t bytes_read; /* number of bytes read from the file */
ssize_t bytes_written; /* number of bytes written to stdout */
int file_descriptor; /* file descriptor for the file */

if (!filename) /* if filename is NULL, return 0 */
return (0);

if (!letters)
/* if letters is 0, nothing to read and print, return 0 */
return (0);

file_descriptor = open(filename, O_RDONLY);
/* open the file in read-only mode */

if (file_descriptor == -1) /* if open() fails, return 0 */
return (0);

buffer = malloc(sizeof(char) * letters);
/* allocate memory for the buffer */

if (!buffer) /* if malloc() fails, return 0 */
{
close(file_descriptor); /* close the file descriptor */
return (0);
}

bytes_read = read(file_descriptor, buffer, letters);
/* read up to letters bytes from the file */

close(file_descriptor); /* close the file descriptor */

if (bytes_read < 0) /* if read() fails, free the buffer and return 0 */
{
free(buffer);
return (0);
}

if (!bytes_read)
/* if read() returns 0, nothing was read from the file */
bytes_read = letters;
/* set bytes_read to letters */

bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
/* write buffer to stdout */

free(buffer); /* free the buffer */

if (bytes_written < 0) /* if write() fails, return 0 */
return (0);

if ((size_t)bytes_written != (size_t)bytes_read)
/* if write() returns an unexpected number of bytes, return 0 */
return (0);

return (bytes_read);
/* return the actual number of letters read and printed */
}
