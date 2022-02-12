/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/12 11:59:20 by cybattis         ###   ########.fr       */
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
			fdf->screen_map[i][j].v.x = p.x + WIN_W / 2;
			fdf->screen_map[i][j].v.y = p.y + WIN_H / 2;
			j++;
		}
		if (DB_MATRIX == 1)
			ft_dprintf(2, "\n");
		i++;
	}
}
