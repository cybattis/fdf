/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/02 23:23:08 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	**ortho_projection_matrix(void)
{
	double	**m;

	return (m);
}

double	**rotation_x_matrix(double angle)
{
	double	**m;

	return (m);
}

double	**rotation_y_matrix(double angle)
{
	double	**m;

	return (m);
}

double	**rotation_z_matrix(double angle)
{
	double	**m;

	return (m);
}

// TODO: typedef t_matrix44d double **
// TODO: to be added to the libft
t_vec4	*matrix_multv4(const t_vec4 *v, double **m)
{
	float	w;
	t_vec3	*out;

	out->x = v->x * m[0][0] + v->y * m[1][0] + v->z * m[2][0] + m[3][0];
	out->y = v->x * m[0][1] + v->y * m[1][1] + v->z * m[2][1] + m[3][1];
	out->z = v->x * m[0][2] + v->y * m[1][2] + v->z * m[2][2] + m[3][2];
	w = v->x * m[0][3] + v->y * m[1][3] + v->z * m[2][3] + m[3][3];
	if (w != 1)
	{
		out->x /= w;
		out->y /= w;
		out->z /= w;
	}
	return (out);
}
