/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:32:25 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/09 16:40:04 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*parse_line(char *line, t_vec2 *size, int i);
static int		parse_color(char *str);

void	get_matrix_size(char *path, t_vec2 *size)
{
	int		i;
	float	prev_size;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	ft_ferror(fd);
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		strtrimr(line);
		i = 0;
		prev_size = 0;
		while (line[i++])
		{
			if (line[i] == ' ')
				prev_size++;
			while (line[i] == ' ')
				i++;
		}
		size->x = prev_size + 1;
		size->y++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
}

t_map	**get_map(char *path, t_vec2 *map_size)
{
	int		i;
	char	*line;
	int		fd;
	t_map	**map;

	fd = open(path, O_RDONLY);
	ft_ferror(fd);
	i = 0;
	map = malloc(sizeof(t_map *) * map_size->y);
	line = ft_get_next_line(fd);
	while (line != NULL && i < map_size->y)
	{
		map[i] = parse_line(line, map_size, i);
		i++;
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (map);
}

static t_map	*parse_line(char *line, t_vec2 *size, int i)
{
	t_map	*map_line;
	char	**line_split;
	int		off_set;
	int		j;

	j = 0;
	off_set = 0;
	line_split = ft_split(line, ' ');
	free(line);
	map_line = malloc(sizeof(t_map) * size->x);
	if (!map_line)
		exit(EXIT_FAILURE);
	while (j < size->x)
	{
		if ((-size->x / 2) + j >= 0 && (int)size->x % 2 == 0)
			off_set = 1;
		map_line[j].v.x = (-size->x / 2) + j + off_set;
		map_line[j].v.y = ft_atoi(line_split[j]);
		map_line[j].v.z = (size->y / 2) + j - i;
		map_line[j].color = parse_color(line_split[j]);
		j++;
	}
	ft_free_all(line_split, size->x);
	return (map_line);
}

static int	parse_color(char *str)
{
	int	w;

	w = 0;
	while (str[w])
	{
		if (str[w] == 'x')
			return (ft_atoi_base(&str[w + 1], "0123456789abcdef"));
		w++;
	}
	return (0);
}
