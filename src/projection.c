/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/08 16:56:50 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ortho_matrix(t_vec2 screen, t_vec2 dist, t_matrix *matrix);

void	screen_projection(t_fdf *fdf, t_matrix *projection)
{
	t_matrix	view;
	t_matrix	ortho;

	ortho_matrix(fdf->screen, vec2(10, 50), &ortho);
	model_to_view_matrix(&view, fdf->t, vec3(0.0, 0.0, -10));
	matrix_mult44(view.m, ortho.m, projection);
	if (DEBUG == 1)
	{
		ft_dprintf(1, "\northo matrix\n");
		print_matrix44(ortho.m);
		ft_dprintf(1, "\n projection \n");
		print_matrix44(projection->m);
	}
}

void	map_projection(t_fdf *fdf, t_matrix *projection)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->map_size.y)
	{
		j = 0;
		while (j < fdf->map_size.x)
		{
			// screen_map[i][j] = matrix_mult44v3(&map->v[i][j], projection);
			j++;
		}
		i++;
	}
}

static void	ortho_matrix(t_vec2 screen, t_vec2 dist, t_matrix *matrix)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = 1 / screen.x;
	matrix->m[1][1] = 1 / screen.y;
	matrix->m[2][2] = -(2 / dist.x - dist.y);
	matrix->m[2][3] = -(dist.x + dist.y / dist.x - dist.y);
	matrix->m[3][3] = 1;
}
