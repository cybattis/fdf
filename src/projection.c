/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/15 23:00:13 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_projection(t_app *fdf, t_matrix *projection)
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
			fdf->screen_map[i][j].v.z = -p.z;
			j++;
		}
		i++;
	}
}

void	animation(t_app *fdf)
{
	if ((fdf->flags & ANIM_ON) != 0)
	{
		fdf->t.rotation.y += 0.05;
		fdf->t.rotation.x += 0.05;
	}
}
