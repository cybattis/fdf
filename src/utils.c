/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:27:01 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/04 17:29:18 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_color(int trgb)
{
	ft_dprintf(2, "Color:%x | t:%d r:%d g:%d b:%d\n", trgb,
		get_t(trgb), get_r(trgb), get_g(trgb), get_b(trgb));
	return (0);
}

void	ft_ferror(int fd)
{
	if (fd < 0)
	{
		ft_dprintf(2, "Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	free_matrix(t_vec3 **map, size_t i)
{
	while (i)
		free(map[i--]);
	free(map[i]);
	free(map);
}

void	ft_print_map(t_vec3 **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			ft_dprintf(2, "%3d ", (int)matrix[i][j++].z);
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

void	print_matrix44(t_matrix44f m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dprintf(1, "[%3f, %3f, %3f, %3f]\n",
			m[i][0], m[i][1], m[i][2], m[i][3]);
		i++;
	}
}
