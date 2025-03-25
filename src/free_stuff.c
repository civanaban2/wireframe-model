/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:41:09 by cari              #+#    #+#             */
/*   Updated: 2025/03/25 06:52:07 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split)
{
	char	**tmp;

	tmp = split;
	while (*split)
		free(*split++);
	free(*split);
	free(tmp);
}

void	free_points(t_point **points, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(points[i++]);
	free(points);
}
