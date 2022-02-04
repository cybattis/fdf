/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:49:06 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/04 23:17:28 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotation_x_matrix(t_matrix *matrix, float angle);
static void		rotation_y_matrix(t_matrix *matrix, float angle);
static void		rotation_z_matrix(t_matrix *matrix, float angle);

void	rotation_matrix(t_matrix *p_x, t_vec3 angle)
{
	t_matrix	rotx;
	t_matrix	roty;
	t_matrix	rotz;
	t_matrix	p_zy;

	ft_memset(p_x->m, 0, sizeof(t_matrix));
	ft_memset(p_zy.m, 0, sizeof(t_matrix));
	rotation_x_matrix(&rotx, angle.x);
	rotation_y_matrix(&roty, angle.y);
	rotation_z_matrix(&rotz, angle.z);
	matrix_mult44(rotz.m, roty.m, &p_zy);
	matrix_mult44(p_zy.m, rotx.m, p_x);
}

static void	rotation_x_matrix(t_matrix *matrix, float angle)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = 1;
	matrix->m[1][1] = cos(angle * (M_PI / 180));
	matrix->m[1][2] = sin(angle * (M_PI / 180));
	matrix->m[2][1] = -sin(angle * (M_PI / 180));
	matrix->m[2][2] = cos(angle * (M_PI / 180));
	matrix->m[3][3] = 1;
}

static void	rotation_y_matrix(t_matrix *matrix, float angle)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = cos(angle * (M_PI / 180));
	matrix->m[0][2] = -sin(angle * (M_PI / 180));
	matrix->m[1][1] = 1;
	matrix->m[2][0] = sin(angle * (M_PI / 180));
	matrix->m[2][2] = cos(angle * (M_PI / 180));
	matrix->m[3][3] = 1;
}

static void	rotation_z_matrix(t_matrix *matrix, float angle)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = cos(angle * (M_PI / 180));
	matrix->m[0][1] = sin(angle * (M_PI / 180));
	matrix->m[1][0] = -sin(angle * (M_PI / 180));
	matrix->m[1][1] = cos(angle * (M_PI / 180));
	matrix->m[2][2] = 1;
	matrix->m[3][3] = 1;
}
