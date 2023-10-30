#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX
 * standard output
 * @filename: txt file
 * @letters: number of letters it should read and print
 * Return: actual number of letters it could read and print, if filename
 * is NULL return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd;
	ssize_t num_written;
	ssize_t num_read;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	num_read = read(fd, buffer, letters);
	num_written = write(STDOUT_FILENO, buffer, num_read);

	if (num_written == -1 || num_written != num_read)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (num_written);
}
