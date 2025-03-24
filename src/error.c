/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:43:29 by cari              #+#    #+#             */
/*   Updated: 2025/03/24 21:02:25 by cari             ###   ########.fr       */
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
}

void	ft_error(char *message)
{
	ft_printf("%s", message);
	exit(1);
}
