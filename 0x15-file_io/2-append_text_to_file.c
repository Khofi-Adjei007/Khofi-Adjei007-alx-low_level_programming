#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>


/**
* append_text_to_file - Appends text_content to the end of a file.
* @filename: Name of the file to which text_content should be appended.
* @text_content: Text to append to filename.
*
* Return: 1 on success, -1 on failure.
*/


int append_text_to_file(const char *filename, char *text_content)
{
int felb, length;

/* Check if filename is NULL */
if (filename == NULL)
return (-1);

/* Open file for writing and appending */
felb = open(filename, O_APPEND | O_WRONLY);
if (felb == -1)
return (-1);

/* Compute the length of the text to be appended */
for (length = 0; text_content && text_content[length]; length++)
;

/* Append the text to the file */
if (write(felb, text_content, length) != length)
{
close(felb);
return (-1);
}

/* Close the file and return success */
close(felb);
return (1);
}

