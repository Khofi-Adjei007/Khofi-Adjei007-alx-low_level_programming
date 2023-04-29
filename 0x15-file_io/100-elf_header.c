#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);

/**
* main - main function of the ELF file header reader.
* @ac: Number of arguments
* @av: Arguments
* Return: 0 on success, 1 otherwise.
*/
int main(int ac, char **av)
{
int fd, len_read;
Elf64_Ehdr e_hdr;

if (ac != 2)
dprintf(STDERR_FILENO, "Usage: %s <elf_filename>\n", av[0]);

fd = open(av[1], O_RDONLY);
if (fd < 0)
{
dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", av[1]);
return (1);
}

len_read = read(fd, &e_hdr, sizeof(e_hdr));
if (len_read < (int)sizeof(e_hdr))
{
dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", av[1]);
close(fd);
return (1);
}

check_elf(e_hdr.e_ident);
print_magic(e_hdr.e_ident);
print_class(e_hdr.e_ident);
print_data(e_hdr.e_ident);
print_version(e_hdr.e_ident);
print_abi(e_hdr.e_ident);
print_osabi(e_hdr.e_ident);

close(fd);
return (0);
}

/**
* check_elf - Checks if a file is an ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not an ELF file - exit code 98.
*/
void check_elf(unsigned char *e_ident)
{
int index;

for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
e_ident[index] != 'E' &&
e_ident[index] != 'L' &&
e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* print_magic - Prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: Magic numbers are separated by spaces.
*/
void print_magic(unsigned char *e_ident)
{
int index;

printf("  Magic:   ");

for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);

if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
* print_class - Prints the class of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_class(unsigned char *e_ident)
{
printf("  Class:                             ");

switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
* print_data - Prints
*/
