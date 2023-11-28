#include "main.h"

/**
 * create_file - Make a new file.
 * @filename: A pointer to the name of the new file.
 * @text_content: A pointer to a string to put in the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
		w = write(fd, text_content, len);
		if (w == -1)
			return (-1);
	}

	close(fd);

	return (1);
}