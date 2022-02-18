/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:25:59 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:16:49 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	matrix_mult44(float m1[][4], float m2[][4], t_matrix *out)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		out->m[i][0] = m1[i][0] * m2[0][0] + m1[i][1] * m2[1][0]
			+ m1[i][2] * m2[2][0] + m1[i][3] * m2[3][0];
		out->m[i][1] = m1[i][0] * m2[0][1] + m1[i][1] * m2[1][1]
			+ m1[i][2] * m2[2][1] + m1[i][3] * m2[3][1];
		out->m[i][2] = m1[i][0] * m2[0][2] + m1[i][1] * m2[1][2]
			+ m1[i][2] * m2[2][2] + m1[i][3] * m2[3][2];
		out->m[i][3] = m1[i][0] * m2[0][3] + m1[i][1] * m2[1][3]
			+ m1[i][2] * m2[2][3] + m1[i][3] * m2[3][3];
		i++;
	}
}

t_vec3	matrix_mult44v3(const t_vec3 *v, t_matrix *matrix)
{
	float	w;
	t_vec3	out;

	out.x = v->x * matrix->m[0][0] + v->y * matrix->m[0][1]
		+ v->z * matrix->m[0][2] + matrix->m[0][3];
	out.y = v->x * matrix->m[1][0] + v->y * matrix->m[1][1]
		+ v->z * matrix->m[1][2] + matrix->m[1][3];
	out.z = v->x * matrix->m[2][0] + v->y * matrix->m[2][1]
		+ v->z * matrix->m[2][2] + matrix->m[2][3];
	w = v->x * matrix->m[3][0] + v->y * matrix->m[3][1]
		+ v->z * matrix->m[3][2] + matrix->m[3][3];
	if (w != 1)
	{
		out.x /= w;
		out.y /= w;
		out.z /= w;
	}
	return (out);
}
