#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <string.h>

/**
 * test_for_exec - test if a file is an elf file
 * @e_ident: Array that identified the header file
 */

void test_for_exec(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 && e_ident[EI_MAG1] != ELFMAG1 &&
e_ident[EI_MAG2] != ELFMAG2 && e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "file is not an executable\n");
		exit(98);
	}
}

/**
 * print_magic - a function to print magic numbers contained in the header
 * @e_ident: Array that identifies the header file
 */

void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:                             ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			putchar('\n');
		else
			putchar(' ');
	}
}

/**
 * print_class - a function to print class of elf file
 * @e_ident: an array of elf header details
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
			printf("<Invalid class: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - a function to print the endianness of file
 * @e_ident: an array of elf header information
 */

void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Unknown DATA format\n");
	}
}

/**
 * print_version - a function to print version
 * @e_ident: an array of elf header information
 */

void print_version(unsigned char *e_ident)
{
	printf("  Version:                           ");
	switch (e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("0 (invalid)\n");
			break;
		case EV_CURRENT:
			printf("1 (current)\n");
			break;
		default:
			printf("0 (invalid)\n");
	}
}

/**
 * print_os - a function to print operating system
 * @e_ident: an array of elf header information
 */

void print_os(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE | ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FREEBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("UNIX - ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Stand-alone\n");
			break;
		default:
			printf("<Unknown: %d>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abi_version - a function to print abi version
 * @e_ident: an array of elf file header details
 */

void print_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
e_ident[EI_ABIVERSION]);
}

/**
 * print_type - a elf file to print type of file
 * @e_type: the type code of elf file
 */

void print_type(unsigned int e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("<Unknown type>\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown type\n");
	}
}

/**
 * print_entry - a function to entry point address of elf_file
 * @entry: entry point address of elf file
 */

void print_entry(unsigned long int entry)
{
	printf("  Entry point address:               ");
	printf("%#lx\n", entry);
}

/**
 * close_elf - a function to close elf file
 * @fd: file descriptor
 */

void close_elf(int fd)
{
	int c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error Unable to close file %d\n", fd);
		exit(98);
	}
}

/**
 * print_elf_header - print the content of header
 * @elf_header: the header contain the header content of the elf file
 * @filename: name of executable file
 * @fd: file descriptor
 */

void print_elf_header(Elf64_Ehdr *elf_header, char *filename, int fd)
{
	printf("ELF Header:\n");
	print_magic(elf_header->e_ident);
	print_class(elf_header->e_ident);
	print_data(elf_header->e_ident);
	print_version(elf_header->e_ident);
	print_os(elf_header->e_ident);
	print_abi_version(elf_header->e_ident);
	print_type(elf_header->e_type);
	print_entry(elf_header->e_entry);
	free(filename);
	close_elf(fd);
}

/**
 * main - Entry point
 * @argc: number of argument passed to main.
 * @argv: argument to the program.
 * Return: 0 if successful, 1 otherwise
 */

int main(int argc, char *argv[])
{
	Elf64_Ehdr *elf_header;
	int fd, r;
	char *filename;

	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		dprintf(STDERR_FILENO,
"Error: Cannot allocate space for elf header structure\n");
		exit(98);
	}

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	filename = strdup(argv[1]);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Can't open file %s\n", filename);
		exit(98);
	}
	r = read(fd, elf_header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Can't read from file %s\n", filename);
		exit(98);
	}

	test_for_exec(elf_header->e_ident);
	print_elf_header(elf_header, filename, fd);

	return (0);
}
