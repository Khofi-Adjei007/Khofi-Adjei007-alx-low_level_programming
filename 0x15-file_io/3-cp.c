#define _POSIX_C_SOURCE 200809L
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


#define READ_NBYTES 1080 /* Number of bytes to read at a time */

/**
* main - Copies the contents of one file into another.
* @argc: Count of arguments to program.
* @argv: Array of arguments to program.
*
* Return: Returns EXIT_SUCCESS on success,
* or an error code otherwise.
*/

int main(int argc, char *argv[])
{
char *file_from, *file_to;
char buf[READ_NBYTES]; /* Buffer for reading from file */
ssize_t r; /* Bytes read from file */
int fpp, fdw, c = 0;

/* Check that the program is called with exactly 2 arguments */
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

/* Extract the source and destination
 * file paths from the program arguments
*/

file_from = argv[1];
file_to = argv[2];

/* Open the source file for reading */
fpp = open(file_from, O_RDONLY);
if (fpp == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
file_from);
exit(98);
}

/* Open the destination file for writing,
 * create it if it does not exist
*/

/* Set file permissions to 664 */
fdw = open(file_to, O_CREAT | O_TRUNC | O_WRONLY, 00664);
if (fdw == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
exit(99);
}

/* Read from the source file in chunks and
 * write them to the destination file
 */

while ((r = read(fpp, buf, READ_NBYTES)))
write(fdw, buf, r);

/* Close the source file and destination file */
if (close(fdw))
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdw);
c = 1;
}
if (close(fpp))
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fpp);
c = 1;
}

/* If there was any error, exit with error code 100 */
if (c)
exit(100);

/* Otherwise, exit with success code */
exit(EXIT_SUCCESS);
}

