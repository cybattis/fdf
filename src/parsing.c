/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:47:37 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/17 12:05:48 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec3	*parse_line(char *line, int size, int i);

t_vec3	**map_parsing(char *path, int size)
{
	int		i;
	char	*line;
	int		fd;
	t_vec3	**map;

	fd = open(path, O_RDONLY);
	ft_ferror(fd);
	i = 0;
	map = malloc(sizeof(t_vec3 *) * size + 1);
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		map[i] = parse_line(line, size, i);
		i++;
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (map);


}

static t_vec3	*parse_line(char *line, int size, int i)
{
	char	**line_split;
	t_vec3	*map_line;
	int		j;

	j = 0;
	line_split = ft_split(line, ' ');
	free(line);
	map_line = malloc(sizeof(t_vec3) * (size + 1));
	if (!map_line)
		exit(EXIT_FAILURE);
	while (j < size)
	{
		map_line[j] = vec3(j, i, ft_atoi(line_split[j]));
		j++;
	}
	ft_free_all(line_split, size);
	return (map_line);
}

int	get_matrix_size(int argc, char *path)
{
	char	*line;
	int		size;
	int		fd;

	if (argc == 2)
	{
		size = 0;
		fd = open(path, O_RDONLY);
		ft_ferror(fd);
		line = ft_get_next_line(fd);
		while (line)
		{
			size++;
			free(line);
			line = ft_get_next_line(fd);
		}
		close(fd);
		return (size);
	}
	ft_dprintf(2, "Error: wrong number of arguments\nUsage: ./fdf map_path\n");
	exit(EXIT_FAILURE);
}
