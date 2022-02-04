/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:23 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/04 20:33:03 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	translation_matrix(t_matrix *matrix, t_vec3 translation);
static void	scale_matrix(t_matrix *matrix, float scale);

void	world_matrix(t_world w, t_matrix *world_p)
{
	t_matrix	scale;
	t_matrix	translation;
	t_matrix	rotation;
	t_matrix	p_sr;

	ft_memset(world_p->m, 0, sizeof(t_matrix));
	ft_memset(p_sr.m, 0, sizeof(t_matrix));
	translation_matrix(&translation, w.translation);
	rotation_matrix(&rotation, w.rotation);
	scale_matrix(&scale, w.scale);
	matrix_mult44(scale.m, rotation.m, p_sr.m);
	matrix_mult44(p_sr.m, translation.m, world_p->m);
}

static void	translation_matrix(t_matrix *matrix, t_vec3 translation)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = 1;
	matrix->m[1][1] = 1;
	matrix->m[2][2] = 1;
	matrix->m[3][0] = translation.x;
	matrix->m[3][1] = translation.y;
	matrix->m[3][2] = translation.z;
	matrix->m[3][3] = 1;
}

static void	scale_matrix(t_matrix *matrix, float scale)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = scale;
	matrix->m[1][1] = scale;
	matrix->m[2][2] = scale;
	matrix->m[3][3] = 1;
}
