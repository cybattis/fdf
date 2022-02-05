/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:32:25 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/05 19:11:18 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vertex	*parse_line(char *line, t_vec2 size, int i);
static t_vertex	**parsing(char *path, t_vec2 size);
static void		get_matrix_size(char *path, t_vec2 *size);
static int		parse_color(char *str);

t_map	*get_map(int argc, char *path)
{
	t_map	*map;

	if (argc == 2)
	{
		map = malloc(sizeof(t_map) * 1);
		map->size = vec2_zero();
		get_matrix_size(path, &map->size);
		print_vec2(map->size);
		map->v = parsing(path, map->size);
		ft_print_map(*map);
		return (map);
	}
	ft_dprintf(2, "Error: wrong number of arguments\nUsage: ./fdf [map_path]\n");
	exit(EXIT_FAILURE);
}

static t_vertex	**parsing(char *path, t_vec2 size)
{
	int			i;
	char		*line;
	int			fd;
	t_vertex	**v;

	fd = open(path, O_RDONLY);
	ft_ferror(fd);
	i = 0;
	v = malloc(sizeof(t_vertex *) * size.y);
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		v[i] = parse_line(line, size, i);
		i++;
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (v);
}

static t_vertex	*parse_line(char *line, t_vec2 size, int i)
{
	t_vertex	*map_line;
	char		**line_split;
	int			j;

	j = 0;
	line_split = ft_split(line, ' ');
	free(line);
	map_line = malloc(sizeof(t_vertex) * size.x);
	if (!map_line)
		exit(EXIT_FAILURE);
	while (j < size.x)
	{
		map_line[j].x = (-size.x / 2) + j;
		map_line[j].y = ft_atoi(line_split[j]);
		map_line[j].z = (size.y / 2) + j - i;
		map_line[j].color = parse_color(line_split[j]);
		j++;
	}
	ft_free_all(line_split, size.x);
	return (map_line);
}

static int	parse_color(char *str)
{
	int	w;

	w = 0;
	while (str[w])
	{
		if (str[w] == 'x')
			return (ft_atoi_base(str[w + 1], "0123456789ABCDEF"));
		w++;
	}
	return (0);
}

static void	get_matrix_size(char *path, t_vec2 *size)
{
	int		i;
	float	prev_size;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	ft_ferror(fd);
	line = ft_get_next_line(fd);
	if (!line)
		ft_error_msg("map file empty");
	prev_size = 0;
	while (line)
	{
		i = 0;
		while (line[i])
			size->x++;
		if (size->y > 0 && size->x != prev_size)
			ft_error_msg("lines width not equal");
		prev_size = size->x;
		size->y++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
}
