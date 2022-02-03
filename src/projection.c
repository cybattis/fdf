/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/03 15:56:53 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



// TODO: typedef t_matrix44d double **
// TODO: to be added to the libft
t_vec3	*matrix_mult(const t_vec3 *v, double **m)
{
	float	w;
	t_vec3	*out;

	out->x = v->x * m[0][0] + v->y * m[0][1] + v->z * m[0][2] + m[0][3];
	out->y = v->x * m[1][0] + v->y * m[1][1] + v->z * m[1][2] + m[1][3];
	out->z = v->x * m[2][0] + v->y * m[2][1] + v->z * m[2][2] + m[2][3];
	w = v->x * m[3][0] + v->y * m[3][1] + v->z * m[3][2] + m[3][3];
	if (w != 1)
	{
		out->x /= w;
		out->y /= w;
		out->z /= w;
	}
	return (out);
}

double 	**matrix_multm4(double **m, double **out)
{
	float	w;
	t_vec3	*out;

	out->x = v->x * m[0][0] + v->y * m[0][1] + v->z * m[0][2] + m[0][3];
	out->y = v->x * m[1][0] + v->y * m[1][1] + v->z * m[1][2] + m[1][3];
	out->z = v->x * m[2][0] + v->y * m[2][1] + v->z * m[2][2] + m[2][3];
	w = v->x * m[3][0] + v->y * m[3][1] + v->z * m[3][2] + m[3][3];
	if (w != 1)
	{
		out->x /= w;
		out->y /= w;
		out->z /= w;
	}
	return (out);
}
