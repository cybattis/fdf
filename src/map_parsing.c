/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:32:25 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 22:38:49 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_size_x(char *line);
static t_map	*parse_line(char *line, t_vec2 *size, int i);
static int		parse_color(char *str);

void	get_matrix_size(char *path, t_app *fdf)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	ft_ferror(fd);
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		ft_trimr(line);
		fdf->map_size.x = get_size_x(line);
		fdf->map_size.y++;
		free(line);
		line = ft_get_next_line(fd);
	}
	if (fdf->map_size.x == 0 || fdf->map_size.y == 0)
		error_close_app(fdf);
	close(fd);
}

static float	get_size_x(char *line)
{
	int		i;
	float	prev_size;

	i = 0;
	prev_size = 1;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == ' ')
			prev_size++;
		while (line[i] == ' ')
			i++;
		i++;
	}
	return (prev_size);
}

t_map	**get_map(char *path, t_app *fdf)
{
	int		i;
	char	*line;
	int		fd;
	t_map	**map;

	fd = open(path, O_RDONLY);
	ft_ferror(fd);
	i = 0;
	map = malloc(sizeof(t_map *) * fdf->map_size.y);
	if (!map)
		error_close_app(fdf);
	line = ft_get_next_line(fd);
	while (line != NULL && i < fdf->map_size.y)
	{
		map[i] = parse_line(line, &fdf->map_size, i);
		if (!map[i])
		{
			ft_free_2d((void **)map, i);
			error_close_app(fdf);
		}
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
	int		j;
	int		y;

	j = 0;
	line_split = ft_split(line, ' ');
	map_line = malloc(sizeof(t_map) * size->x);
	if (!map_line || !line_split)
		return (NULL);
	free(line);
	while (j < size->x)
	{
		map_line[j].v.x = (-size->x / 2) + j;
		y = ft_atoi(line_split[j]);
		if (y >= size->x / 2 || y >= size->y / 2)
			map_line[j].v.y = y / 2;
		else
			map_line[j].v.y = y;
		map_line[j].v.z = (size->y / 2) - i;
		map_line[j].color = parse_color(line_split[j]);
		j++;
	}
	ft_free_all(line_split, size->x);
	return (map_line);
}

static int	parse_color(char *str)
{
	char	*out;
	int		w;

	w = 0;
	while (str[w])
	{
		if (str[w] == 'x')
		{
			out = ft_str_tolower(&str[w + 1]);
			return (ft_atoi_base(out, "0123456789abcdef"));
		}
		w++;
	}
	return (0);
}
