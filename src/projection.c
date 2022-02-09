/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/09 16:38:32 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_projection(t_fdf *fdf, t_matrix *projection)
{
	t_vec3	p;
	int		i;
	int		j;

	i = 0;
	while (i < fdf->map_size.y)
	{
		j = 0;
		while (j < fdf->map_size.x)
		{
			p = matrix_mult44v3(&fdf->map[i][j].v, projection);
			if (DEBUG == 1)
				dprintf(2, "p [%f, %f, %f] ", ((p.x + WIN_W / 2) / WIN_W) * WIN_W, ((p.y + WIN_H / 2) / WIN_H) * WIN_H, p.z);
			//dprintf(2, "p* [%f, %f, %f] ", p.x * (fdf->screen.x / 2), p.y * (fdf->screen.y / 2), p.z);
			mlx_pixel_put_img(&fdf->frame, ((p.x + WIN_W / 2) / WIN_W) * WIN_W, ((p.y + WIN_H / 2) / WIN_H) * WIN_H, WHITE);
			j++;
		}
		if (DEBUG == 1)
			ft_dprintf(2, "\n");
		i++;
	}
}
