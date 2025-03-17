#include "fdf.h"

void	ft_error(char *message, t_core *core)
{
	free_data(core);
	ft_printf("%s", message);
	exit(1);
}

void	free_data(t_core *core)
{

}

void	arg_check(int argc, char const *argv[], t_core *core)
{
	if (argc != 2)
		ft_error(INVALID_ARGS, core);
	core->fd = open(argv[1], O_RDONLY);
	if (core->fd == -1)
		ft_error(INVALID_FILE, core);
	parse_map(fd, core);
}