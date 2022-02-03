/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:49:06 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/03 16:32:22 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	**rotation_x_matrix(double **m, double angle);
static double	**rotation_y_matrix(double **m, double angle);
static double	**rotation_z_matrix(double **m, double angle);

void	rotation_matrix(t_vec3 v, t_vec3 angle)
{
	ft_memset(m, 0, sizeof(memset));

}

static double	**rotation_x_matrix(t_vec3 v, double angle)
{
	double	m[4][4];

	ft_memset(m, 0, sizeof(memset));
	m[0][0] = 1;
	m[1][1] = cos(angle);
	m[1][2] = sin(angle);
	m[2][1] = -sin(angle);
	m[2][2] = cos(angle);
	m[3][3] = 1;
	return (matrix_multm4());
}

static double	**rotation_y_matrix(t_vec3 v, double angle)
{
	double	m[4][4];

	ft_memset(m, 0, sizeof(memset));
	m[0][0] = cos(angle);
	m[0][2] = -sin(angle);
	m[1][1] = 1;
	m[2][0] = sin(angle);
	m[2][2] = cos(angle);
	m[3][3] = 1;
}

static double	**rotation_z_matrix(t_vec3 v, double angle)
{
	double	m[4][4];

	ft_memset(m, 0, sizeof(memset));
	m[0][0] = cos(angle);
	m[0][1] = sin(angle);
	m[1][0] = -sin(angle);
	m[1][1] = cos(angle);
	m[2][2] = 1;
	m[3][3] = 1;
}
