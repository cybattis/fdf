/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:01:31 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/03 14:59:18 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	**init_map(char *path, int size)
{
	t_vec3	**map;

	// TODO: redo parsing
	map = map_parsing(path, size);
	// map_offset(map, size);
	ft_print_map(map, size);
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
