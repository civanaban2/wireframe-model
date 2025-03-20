/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:48:13 by cari              #+#    #+#             */
/*   Updated: 2025/03/20 20:26:41 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_map(char const *filename, t_map *map)
{
	int 	i;

	map->height = line_counter(filename);
	map->width = index_counter(filename);
	map->points = malloc(sizeof(t_point *) * map->height);
	i = 0;
	while (i < map->height)
		map->points[i++] = malloc(sizeof(t_point) * map->width);
	get_data(filename, map);
}

int	line_counter(char const *filename)
{
	int	fd;
	char *line;
	int count;

	fd = open(filename, O_RDONLY);
	count = 0;
	line = malloc(1);
	while (read(fd, line, 1))
	{
		if (*line == '\n')
			count++;
	}
	close(fd);
	free(line);
	return (count);
}

int	index_counter(char const *filename)
{
	int		fd;
	int		count;
	char	*line;
	char 	**split;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	
	count = 0;
	while (split[count])
		count++;
	close(fd);
	free(line);
	free_split(split);
	return (count);
}

void	get_data(char const *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x = j;
			map->points[i][j].y = i;
			map->points[i][j].z = ft_atoi(split[j]);
			j++;
		}
		i++;
		free(line);
		free_split(split);
	}
}

void	free_split(char **split)
{
	char **tmp;

	tmp = split;
	while (*split)
		free(*split++);
	free(*split);
	free(tmp);
}