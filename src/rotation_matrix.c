/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:49:06 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/15 17:21:56 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotation_x_matrix(t_matrix *matrix, float angle, double pi_180);
static void		rotation_y_matrix(t_matrix *matrix, float angle, double pi_180);
static void		rotation_z_matrix(t_matrix *matrix, float angle, double pi_180);

void	rotation_matrix(t_matrix *p_x, t_vec3 angle)
{
	t_matrix	rotx;
	t_matrix	roty;
	t_matrix	rotz;
	t_matrix	p_zy;
	double		pi_180;

	pi_180 = M_PI / 180;
	ft_memset(p_x->m, 0, sizeof(t_matrix));
	ft_memset(p_zy.m, 0, sizeof(t_matrix));
	rotation_x_matrix(&rotx, angle.x, pi_180);
	rotation_y_matrix(&roty, angle.y, pi_180);
	rotation_z_matrix(&rotz, angle.z, pi_180);
	matrix_mult44(rotz.m, roty.m, &p_zy);
	matrix_mult44(p_zy.m, rotx.m, p_x);
}

static void	rotation_x_matrix(t_matrix *matrix, float angle, double pi_180)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = 1;
	matrix->m[1][1] = cos(angle * pi_180);
	matrix->m[1][2] = sin(angle * pi_180);
	matrix->m[2][1] = -sin(angle * pi_180);
	matrix->m[2][2] = cos(angle * pi_180);
	matrix->m[3][3] = 1;
}

static void	rotation_y_matrix(t_matrix *matrix, float angle, double pi_180)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = cos(angle * pi_180);
	matrix->m[0][2] = -sin(angle * pi_180);
	matrix->m[1][1] = 1;
	matrix->m[2][0] = sin(angle * pi_180);
	matrix->m[2][2] = cos(angle * pi_180);
	matrix->m[3][3] = 1;
}

static void	rotation_z_matrix(t_matrix *matrix, float angle, double pi_180)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = cos(angle * pi_180);
	matrix->m[0][1] = sin(angle * pi_180);
	matrix->m[1][0] = -sin(angle * pi_180);
	matrix->m[1][1] = cos(angle * pi_180);
	matrix->m[2][2] = 1;
	matrix->m[3][3] = 1;
}
