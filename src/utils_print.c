/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:44:17 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/13 16:56:09 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_map	**map, t_vec2 size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			dprintf(2, "[%f, %f, %f, %x]",
				map[i][j].v.x, map[i][j].v.y, map[i][j].v.z, map[i][j].color);
			j++;
		}
		ft_dprintf(2, "\n");
		i++;
	}
}

void	print_vec2(t_vec2 v)
{
	dprintf(2, "[%f, %f]\n", v.x, v.y);
}

void	print_vec3(t_vec3 v)
{
	dprintf(2, "[%f, %f, %f]\n", v.x, v.y, v.z);
}

void	print_matrix44(t_matrix matrix)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dprintf(1, "[%3f, %3f, %3f, %3f]\n",
			matrix.m[i][0], matrix.m[i][1], matrix.m[i][2], matrix.m[i][3]);
		i++;
	}
}

int	print_color(int trgb)
{
	ft_dprintf(2, "Color:%x | t:%d r:%d g:%d b:%d\n", trgb,
		get_t(trgb), get_r(trgb), get_g(trgb), get_b(trgb));
	return (0);
}
