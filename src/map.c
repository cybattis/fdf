/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:01:31 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/01 23:11:02 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	**init_map(char *path, int size)
{
	t_vec3	**map;

	map = map_parsing(path, size);
	map_offset(map, size);
	ft_print_map(map, size);
	return (map);
}

void	update_map(t_vec3 **map, int size)
{
	int		i;
	int		j;
	t_vec3	p;
	t_vec3	r;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			p = matrix_multv4();
			ft_printf("Vector P\n");
			print_vec3(p);
			map[i][j] = p;
			j++;
		}
		i++;
	}
}

void	map_offset(t_vec3 **map, int size)
{
	int		i;
	int		j;
	t_vec3	d;
	t_vec3	offset;

	i = 0;
	d = vec3(35, 35, 0);
	offset = vec3(OX - ((size - 1) * d.x / 2), OY - ((size - 1) * d.y / 2), 0);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			vec3_add(&map[i][j], offset);
			offset.x += d.x;
			j++;
		}
		vec3_add(&offset, vec3(-d.x * size, d.y, 0));
		i++;
	}
}
