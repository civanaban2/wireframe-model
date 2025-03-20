#include "fdf.h"

void	ft_error(char *message)
{
	ft_printf("%s", message);
	exit(1);
}

void	arg_check(int argc, char const *filename)
{
	int fd;
	if (argc != 2)
		ft_error(INVALID_ARGS);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(INVALID_FILE);
	close(fd);
}