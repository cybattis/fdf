/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/01 23:08:33 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec4	ortho_projection_matrix(void)
{
}

t_vec4	rotation_x_matrix(double angle)
{
}

t_vec4	rotation_y_matrix(double angle)
{
}

t_vec4	rotation_z_matrix(double angle)
{
}

t_vec4	*matrix_multv4(const t_vec4 *v, double **m)
{
	float	w;
	t_vec3	*dst;

	dst->x = v->x * m[0][0] + v->y * m[1][0] + v->z * m[2][0] + m[3][0];
	dst->y = v->x * m[0][1] + v->y * m[1][1] + v->z * m[2][1] + m[3][1];
	dst->z = v->x * m[0][2] + v->y * m[1][2] + v->z * m[2][2] + m[3][2];
	w = v->x * m[0][3] + v->y * m[1][3] + v->z * m[2][3] + m[3][3];
	if (w != 1)
	{
		dst->x /= w;
		dst->y /= w;
		dst->z /= w;
	}
	return (dst);
}
