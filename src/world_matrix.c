/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:23 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/04 18:31:03 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	translation_matrix(t_matrix *matrix, t_vec3 translation);
static void	scale_matrix(t_matrix *matrix, float scale);

void	world_matrix(t_vec3 translation, t_vec3 angle, t_vec3 scale)
{
	t_matrix	scale;
	t_matrix	translation;
	t_matrix	rotation;

	translation_matrix(&translation, translation);
	rotation_matrix(&rotation, angle);
	scale_matrix(&scale, 2);
}

static void	translation_matrix(t_matrix *matrix, t_vec3 translation)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
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
