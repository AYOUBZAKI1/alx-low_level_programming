#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#define ElfN_Ehdr 64

int isELF(char *filename);
void print_magic(char *magic);
void architecture(int key);
void data_encoding(int key);
void version_num(int key);
void os_abi(int key);
void file_type(int key);

/**
 * main - displays the info contained in the ELF header
 * @ac: number of runtime args
 * @av: array of runtimes args
 *
 * Return: 0 on success, 98 on error
 */
int main(int ac, char **av)
{
	int fd, ok;
	char magic[17], buf[10];
	off_t offset;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO,
		"Usage: elf_header elf_filename %d\n", ac);
		exit(98);
	}
	fd = open(av[1], O_RDONLY);
	ok = isELF(av[1]);

	/* read from 0 - 16 */
	ok = read(fd, magic, 16);
	if (ok == -1)
		exit(98);

	/* Magic, Class, Data, Version, OS/ABI */
	print_magic(magic);
	architecture(magic[4]);
	data_encoding(magic[5]);
	version_num(magic[6]);
	os_abi(magic[7]);

	printf("  ABI Version:\t\t\t     %d\n", magic[8]);

	/* 16 of unsighed char? */
	offset = 16 * sizeof(unsigned char);

	/* set pointer to 5 then read 5 - 16 */
	offset = lseek(fd, offset, SEEK_SET);
	ok = read(fd, buf, 7);
	if (ok == -1)
		exit(98);
	file_type(buf[0]);
	printf("  Entry point address:\t\t     0x%x\n", buf[3]);
	/**
	  * 0 - type
	  * 1 - machine
	  * 2 - version
	  * 3 - entry
	  * 4 - phoff
	  * 5 - shoff
	  * 6 - flags
	  * 7 - ehsize
	  */

	return (0);
}

/**
 * isELF - checks if a file is an ELF(binary?) file
 * @filename: the file in consideration
 *
 * Return: 0 on success, 98 on failure
 */
int isELF(char *filename)
{
	int fd;
	char *buf;
	char str[] = {0x7F, 'E', 'L', 'F', '\0'};

	/* open potential ELF file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(98);

	buf = malloc(sizeof(char) * 4);
	if (read(fd, buf, 4) == -1)
		exit(98);

	if (strcmp(str, buf) != 0)
	{
		dprintf(STDERR_FILENO, "File %s is not an ELF file\n", filename);
		exit(98);
	}

	return (fd);
}

/**
 * print_magic - hexadecimal values of 1st 16 bytes of an ELF file
 * @magic: the bytes to print
 * Return: nothing
 */
void print_magic(char *magic)
{
	int i;

	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < 15; i++)
		printf("%02x ", magic[i]);
	printf("%02x\n", magic[i]);
}

/**
 * architecture - prints the architecture for a binary
 * @key: the value of it's macro
 * Return: nothing
 */
void architecture(int key)
{
	printf("  Class:\t\t\t     ");
	if (key == 1)
		printf("ELF32\n");
	else if (key == 2)
		printf("ELF64\n");
	else
		printf("ELFNone\n");
}

/**
 * data_encoding - prints the data encoding of data in ELF
 * @key: the 6th byte of ELF
 * Return: nothing
 */
void data_encoding(int key)
{
	printf("  Data:\t\t\t\t     ");
	if (key == 1)
		printf("2's complement, little-endian\n");
	else if (key == 2)
		printf("2's complement, big-endian\n");
	else
		printf("Unknown data format\n");
}

/**
 * version_num - prints version num of the ELF specification
 * @key: the 7th byte of ELF
 * Return: nothing
 */
void version_num(int key)
{
	printf("  Version:\t\t\t     ");
	if (key == 0)
		printf("0 (invalid)\n");
	else
		printf("1 (current)\n");
}

/**
 * os_abi - prints the OS and ABI to which ELF is targeted
 * @key: the 8th byte of ELF file
 * Return: void
 */
void os_abi(int key)
{
	char *str, *s;

	printf("  OS/ABI:\t\t\t     ");
	s = "UNIX - ";
	switch (key)
	{
		case 0:
		case 1:
			str = "System V";
			break;
		case 2:
			str = "HP-UX";
			break;
		case 3:
			str = "NetBSD";
			break;
		case 4:
			str = "Linux";
			break;
		case 5:
			str = "Solaris";
			break;
		case 6:
			str = "IRIX";
			break;
		case 7:
			str = "FreeBSD";
			break;
		case 8:
			str = "TRU64";
			break;
		case 9:
			str = "ARM architecture";
			break;
		case 10:
			s = "";
			sprintf(s, "<unknown: %d>", key);
			str = "";
			break;
	}
	printf("%s%s\n", s, str);
}

/**
 * file_type - identifies and prints the object file type
 * @key: the value of e_type in ELF file
 * Return: nothing
 */
void file_type(int key)
{
	printf("  Type:\t\t\t\t     ");
	if (key == 1)
		printf("REL (relocatable file)\n");
	else if (key == 2)
		printf("EXEC (executable file)\n");
	else if (key == 3)
		printf("DYN (shared object)\n");
	else if (key == 4)
		printf("CORE (core file)\n");
	else
		printf("NONE (unknown type)\n");
}
