#include "main.h"
/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure (file can not be created,
 * file can not be written, write “fails”
 */

int create_file(const char *filename, char *text_content)
{
	int fd, num_written, text_len = 0;

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	num_written = write(fd, text_content, text_len);

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (text_len = 0; text_content[text_len];)
			text_len++;
	}

	if (num_written != text_len)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
