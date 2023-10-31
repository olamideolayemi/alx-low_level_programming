#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define BUFSIZE 1024

char *create_buffer(char *file);
void close_file(int fd);
void print_error(int code, const char *file, int fd);

/**
 * create_buffer - reads 1,024 bytes at a time from the file_from to
 * make less system calls
 * @file: file name
 * Return: pointer to new aloocated buffer
 */

char *create_buffer(char *file)
{
	char *num_buffer;

	num_buffer = malloc(sizeof(char) * 1024);

	if (num_buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (num_buffer);
}

/**
 * close_file - closes file descriptors
 * @fd: file descriptor
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of argumenst supplied
 * @argv: an array of pointers to arguments
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	int from, to;
	ssize_t num_read, num_write;
	char num_buffer[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from = open(argv[1], O_RDONLY);
	if (from == -1)
		print_error(98, argv[1], from);

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
		print_error(99, argv[2], to);

	while ((num_read = read(from, num_buffer, BUFSIZE) > 0))
	{
		num_write = write(to, num_buffer, num_read);
		if (num_write == -1)
			print_error(99, argv[2], to);
	}
	if (num_read == -1)
		print_error(98, argv[1], from);
	if (close(from) == -1 || close(to) == -1)
		print_error(100, NULL, -1);

	return (0);
}

/**
 * print_error - prints error message
 * @code: exit code
 * @file: file to exit
 * @fd: file description
 */
void print_error(int code, const char *file, int fd)
{
	if (file)
		dprintf(STDERR_FILENO, "Error: Can't %s from file %s\n",
				(code == 98) ? "read" : "write", file);
	else
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);

	exit(code);
}
