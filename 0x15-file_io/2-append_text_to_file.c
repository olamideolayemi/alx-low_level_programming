#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: the NULL terminated string to add at the end of
 * the file
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, num_written, text_len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		text_len = 0;

		while (text_content[text_len] != '\0')
			text_len++;

		num_written = write(fd, text_content, text_len);

		if (num_written != text_len)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
