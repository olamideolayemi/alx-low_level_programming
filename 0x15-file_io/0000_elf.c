#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void validateElf(unsigned char *ident);
void displayMagicNumbers(unsigned char *ident);
void displayElfClass(unsigned char *ident);
void printDataEncodingInfo(unsigned char *ident);
void printElfVersionInfo(unsigned char *ident);
void printOsAbiInfo(unsigned char *ident);
void print_abi(unsigned char *ident);
void printElfTypeInfo(unsigned int elfType, unsigned char *ident);
void printEntryPointInfo(unsigned long int entryPoint, unsigned char *ident);
void closeFileDescriptor(int fileDesc);

/**
 * validateElf - checks if file is an ELF file
 * @ident: ponter to an array containing ELF magic numbers
 */
void validateElf(unsigned char *ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (ident[i] != 127 && ident[i] != 'E' && ident[i]
				!= 'L' && ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * displayMagicNumbers - prints magic number of an ELF h
 * @ident: pointer to an array containing ELF magic numbers
 */
void displayMagicNumbers(unsigned char *ident)
{
	int i;

	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", ident[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * displayElfClass - prints the class of an ELF headr
 * @ident: pointer to an array containing ELF magic numbers
 */
void displayElfClass(unsigned char *ident)
{
	printf(" Class: ");
	switch (ident[EI_CLASS])
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
			printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * printDataEncodingInfo - prints the data of an ELF header
 * @ident: pointer to an array containing ELF magic numbers
 */
void printDataEncodingInfo(unsigned char *ident)
{
	printf(" Data: ");
	switch (ident[EI_DATA])
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
			printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * printElfVersionInfo - prints the version information of an ELF header
 * @ident: pointer to an array containing ELF magic numbers
 */
void printElfVersionInfo(unsigned char *ident)
{
	printf(" Version: %d", ident[EI_VERSION]);
	switch (ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * printOsAbiInfo - prints OS / ABI information of an ELF header
 * @ident: pointer to an array containing ELF magic numbers
 */
void printOsAbiInfo(unsigned char *ident)
{
	printf(" OS/ABI: ");
	switch (ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
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
			printf("<unknown: %x>\n", ident[EI_OSABI]);
	}
}

/**
 * print_abi - prints ABI version information of an ELF header
 * @ident: pointer to an array containing ELF magic numbers
 */
void print_abi(unsigned char *ident)
{
	printf(" ABI Version: %d\n",
			ident[EI_ABIVERSION]);
}

/**
 * printElfTypeInfo - prints the ELF type
 * @elfType: ELF type
 * @ident: pointer to an array containing ELF class
 */
void printElfTypeInfo(unsigned int elfType, unsigned char *ident)
{
	if (ident[EI_DATA] == ELFDATA2MSB)
		elfType >>= 8;
	printf(" Type: ");
	switch (elfType)
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
			printf("<unknown: %x>\n", elfType);
	}
}

/**
 * printEntryPointInfo - prints the entry point of an ELF header
 * entryPoint: address of the ELF entry point
 * @ident: pointer to an array containing ELF class
 */
void printEntryPointInfo(unsigned long int entryPoint,
		unsigned char *ident)
{
	printf(" Entry point address: ");
	if (ident[EI_DATA] == ELFDATA2MSB)
	{
		entryPoint = ((entryPoint << 8) & 0xFF00FF00) |
			((entryPoint >> 8) & 0xFF00FF);
		entryPoint = (entryPoint << 16) | (entryPoint >> 16);
	}
	if (ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entryPoint);
	else
		printf("%#lx\n", entryPoint);
}

/**
 * closeFileDescriptor - closes the ELF file
 * @fileDesc: file descriptor
 */
void closeFileDescriptor(int fileDesc)
{
	if (close(fileDesc) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileDesc);
		exit(98);
	}
}

/**
 * main - displays the information contained in the ELF header at
 * the start of an ELF file
 * @argc: arguments supplied to the program
 * @argv: array of pointers
 * Return: 0 (Success)
 */
int main(int __attribute__((__unused__))
		argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fileDesc, resultCode;

	fileDesc = open(argv[1], O_RDONLY);

	if (fileDesc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeFileDescriptor(fileDesc);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	resultCode = read(fileDesc, header, sizeof(Elf64_Ehdr));
	if (resultCode == -1)
	{
		free(header);
		closeFileDescriptor(fileDesc);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	validateElf(header->e_ident);
	printf("ELF Header:\n");
	displayMagicNumbers(header->e_ident);
	displayElfClass(header->e_ident);
	printDataEncodingInfo(header->e_ident);
	printElfVersionInfo(header->e_ident);
	printOsAbiInfo(header->e_ident);
	print_abi(header->e_ident);
	printElfTypeInfo(header->e_type, header->e_ident);
	printEntryPointInfo(header->e_entry, header->e_ident);
	free(header);
	closeFileDescriptor(fileDesc);
	return (0);

}
