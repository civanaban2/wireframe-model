/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:43:29 by cari              #+#    #+#             */
/*   Updated: 2025/03/28 12:38:29 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	arg_check(int argc, char const *filename)
{
	int	fd;

	if (argc != 2)
		ft_error(INVALID_ARGS);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(INVALID_FILE);
	close(fd);
	name_control(filename);
}

void	ft_error(char *message)
{
	ft_printf("%s", message);
	exit(1);
}

void	name_control(char const *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 5)
		ft_error(INVALID_FORMAT);
	if (filename[i - 1] != 'f' || filename[i - 2] != 'd'
		|| filename[i - 3] != 'f' || filename[i - 4] != '.'
		|| filename[i - 5] == '/')
		ft_error(INVALID_FORMAT);
}
