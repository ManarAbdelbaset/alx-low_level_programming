#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file to read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters it could read and print, or 0 if failed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n, r;
	char *buf;

	if (!filename)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (!buf)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	n = read(fd, buf, letters);
	if (n == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	buf[n] = '\0';

	r = write(STDOUT_FILENO, buf, n);
	if (r == -1 || r != n)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);

	return (n);
}
