/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:01:31 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/04 20:40:22 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	**init_map(char *path, int size)
{
	t_world		w;
	t_matrix	world_p;
	t_vertex	**map;

	// TODO: redo parsing
	map = map_parsing(path, size);
	w.scale = 10;
	w.rotation = vec3(30, 20, 40);
	w.translation = vec3(5, 10, 42);
	world_matrix(w, &world_p);
	dprintf(1, "\nWorld projection\n");
	print_matrix44(world_p.m);
	//ft_print_map(map, size);
	return (map);
}

//TODO: get new function name
void	update_map(t_vec3 **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			// make dot product
			map[i][j];
			j++;
		}
		i++;
	}
}
