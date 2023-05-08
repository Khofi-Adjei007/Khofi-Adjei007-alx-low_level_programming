#include "main.h"

/**
* _strlen – This calculates the full length of a null-terminated string.
* @str: This is the string for measurement.
* Return: This checks length of @str, or -1 if @str is NULL.
*/

ssize_t _strlen(const char *str)
{
ssize_t len = 0;
if (!str)
return (-1);
while (*str++)
++len;
return (len);
}

/**
* create_file – Here this creates a file and writes a data to it
* @filename: This is the name of the file to be created.
* @text_content: Here, this is the data to be write to @filename.
* Return: On success, return 1. Else, return -1.
*/

int create_file(const char *filename, char *text_content)
{
ssize_t b_written = 0;
int fe;
if (!filename)
return (-1);

fe = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fe < 0)
return (-1);
if (text_content)
b_written = write(fe, text_content, _strlen(text_content));

close(fe);

if (b_written < 0)
return (-1);

return (1);
}
