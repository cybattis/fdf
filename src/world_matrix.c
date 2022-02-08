/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:35:23 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/08 16:57:40 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	world_matrix(t_transform t, t_matrix *world);
static void	camera_matrix(t_matrix *matrix, t_vec3 translation);
static void	translation_matrix(t_matrix *matrix, t_vec3 translation);
static void	scale_matrix(t_matrix *matrix, float scale);

void	model_to_view_matrix(t_matrix *view, t_transform t, t_vec3 eye_dist)
{
	t_matrix	camera;
	t_matrix	world;

	camera_matrix(&camera, eye_dist);
	world_matrix(t, &world);
	matrix_mult44(world.m, camera.m, view);
	if (DEBUG == 1)
	{
		ft_dprintf(1, "\nWorld projection\n");
		print_matrix44(world.m);
		ft_dprintf(1, "\ncamera projection\n");
		print_matrix44(camera.m);
	}
}

static void	world_matrix(t_transform t, t_matrix *world)
{
	t_matrix	scale;
	t_matrix	translation;
	t_matrix	rotation;
	t_matrix	p_sr;

	ft_memset(p_sr.m, 0, sizeof(t_matrix));
	ft_memset(world->m, 0, sizeof(t_matrix));
	scale_matrix(&scale, t.scale);
	rotation_matrix(&rotation, t.rotation);
	translation_matrix(&translation, t.translation);
	matrix_mult44(scale.m, rotation.m, &p_sr);
	matrix_mult44(p_sr.m, translation.m, world);
}

static void	translation_matrix(t_matrix *matrix, t_vec3 translation)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = 1;
	matrix->m[1][1] = 1;
	matrix->m[2][2] = 1;
	matrix->m[0][3] = translation.x;
	matrix->m[1][3] = translation.y;
	matrix->m[2][3] = translation.z;
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

static void	camera_matrix(t_matrix *matrix, t_vec3 translation)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = 1;
	matrix->m[1][1] = 1;
	matrix->m[2][2] = 1;
	matrix->m[0][3] = translation.x;
	matrix->m[1][3] = translation.y;
	matrix->m[2][3] = translation.z;
	matrix->m[3][3] = 1;
}
