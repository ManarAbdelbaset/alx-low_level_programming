#include "main.h"
#include <elf.h>

/**
 * error_exit - prints an error message and exits with status code 98
 * @msg: error message to print
 */
void error_exit(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_magic - prints the magic bytes of the ELF file
 * @e_ident: array of the magic bytes
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e_ident[i], i < EI_NIDENT - 1 ? " " : "\n");
}

/**
 * print_class - prints the class (32 or 64 bit) of the ELF file
 * @e_ident: array of the magic bytes
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
 * print_data - prints the endianness of the ELF file
 * @e_ident: array of the magic bytes
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
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * print_version - prints the version of the ELF file
 * @e_ident: array of the magic bytes
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_NONE)
		printf(" (invalid)\n");
	else if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi - prints the OS/ABI of the ELF file
 * @e_ident: array of the magic bytes
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_SYSV:
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
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_type - prints the type of the ELF file
 * @e_type: type stored in the ELF header
 */
void print_type(uint16_t e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - prints the entry point address of the ELF file
 * @e_entry: entry point address stored in the ELF header
 */
void print_entry(uintptr_t e_entry)
{
	printf("  Entry point address:               %p\n", (void *)e_entry);
}

/**
 * print_elf_header - prints information from the ELF header
 * @ehdr: ELF header structure
 */
void print_elf_header(Elf64_Ehdr *ehdr)
{
	if (memcmp(ehdr->e_ident, ELFMAG, SELFMAG) != 0)
		error_exit("Error: not an ELF file");

	print_magic(ehdr->e_ident);
	print_class(ehdr->e_ident);
	print_data(ehdr->e_ident);
	print_version(ehdr->e_ident);
	print_osabi(ehdr->e_ident);
	printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);
	print_type(ehdr->e_type);
	print_entry(ehdr->e_entry);
}

/**
 * main - displays the information contained in the ELF header at the start
 *        of an ELF file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, otherwise exit status code
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]), exit(98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: couldn't open %s\n", argv[1]), exit(98);

	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
		error_exit("Error: couldn't read file header");

	print_elf_header(&ehdr);

	if (close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: couldn't close file descriptor\n"), exit(100);

	return (0);
}
