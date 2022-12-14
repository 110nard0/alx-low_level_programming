#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of file to be read
 * @letters: number of letters to be read and printed
 * Return: integer (actual number of letters read and printed) or 0 (fail)
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t size, print, len;
	char *buffer;

	if (filename == NULL)
		return (0);
	/* open */
	fd = open(filename, O_RDONLY, 0400);
	if (fd == -1)
		return (0);

	/* get file size and allocate memory */
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buffer = malloc(size + 1);
	if (buffer == NULL)
		return (0);

	/* read */
	len = read(fd, buffer, letters);
	buffer[++size] = '\0';
	if (len == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* write */
	print = write(STDOUT_FILENO, buffer, len);
	if (print == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	close(fd);
	free(buffer);
	return (len);
}

