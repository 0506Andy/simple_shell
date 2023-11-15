#include "main.h"

/**
 * custom_open - opens a file
 * @pathname:the path of the file to open
 * @flags:flags to use when opening file
 * @mode:permissiond set for the file
 * Return:file descriptor (fd)
 */
int custom_open(const char *pathname, int flags, mode_t mode)
{
	int fd;

	fd = open(pathname, flags, mode);
	if (fd == -1)
	{
		perror("open");
	}
	return (fd);
}

/**
 * custom_read - reads data from fd
 * @fd: file descriptor to read from
 * @buf:data is stored here
 * @count:max num of bytes
 * Return:br
 */
ssize_t custom_read(int fd, void *buf, size_t count)
{
	ssize_t br;

	br = read(fd, buf, count);

	if (br == -1)
	{
		perror("read");
	}
	return (br);
}

/**
 * custom_write - writes data to fd
 * @fd: file descriptor to write to
 * @buf: data to be written
 * @count: bytes to write
 * Return: bw(bytes written)
 */
ssize_t custom_write(int fd, const void *buf, size_t count)
{
	ssize_t bw;

	bw = write(fd, buf, count);

	if (bw == -1)
	{
		perror("write");
	}
	return (bw);
}

/**
 * custom_close - close fd
 * @fd :file descriptor to close
 * Return:result
 */
int custom_close(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		perror("close");
	}
	return (result);
}

/**
 * custom_fork - creates new process
 * Return:void
 */
pid_t custom_fork(void)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
	}
}
