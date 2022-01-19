/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/19 18:22:57 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	projection_2d(t_vec3 v)
{
	t_vec3	rx[3];

	rx[0] = vec3(1.0, 0.0, 0.0);
	rx[1] = vec3(0.0, 1.0, 0.0);
	rx[2] = vec3(0.0, 0.0, 0.0);
	return (matrix_mult(&v, rx));
}

t_vec3	rotation_x(t_vec3 *v, double angle)
{
	t_vec3	rx[3];

	rx[0] = vec3(1.0, 0.0, 0.0);
	rx[1] = vec3(0.0, cos(angle), -sin(angle));
	rx[2] = vec3(0.0, sin(angle), cos(angle));
	return (matrix_mult(v, rx));
}

t_vec3	rotation_y(t_vec3 *v, double angle)
{
	t_vec3	rx[3];

	rx[0] = vec3(cos(angle), 0.0, sin(angle));
	rx[1] = vec3(0.0, 1.0, 0.0);
	rx[2] = vec3(-sin(angle), 0.0, cos(angle));
	return (matrix_mult(v, rx));
}

t_vec3	rotation_z(t_vec3 *v, double angle)
{
	t_vec3	rx[3];

	rx[0] = vec3(cos(angle), -sin(angle), 0.0);
	rx[1] = vec3(sin(angle), cos(angle), 0.0);
	rx[2] = vec3(0.0, 0.0, 1.0);
	return (matrix_mult(v, rx));
}

t_vec3	matrix_mult(t_vec3 *v, t_vec3 *projection)
{
	t_vec3	r;
	t_vec3	*px;
	t_vec3	*py;
	t_vec3	*pz;

	px = vec3_multv3(&projection[0], *v);
	r.x = px->x + px->y + px->z;
	py = vec3_multv3(&projection[1], *v);
	r.y = py->x + py->y + py->z;
	pz = vec3_multv3(&projection[2], *v);
	r.z = pz->x + pz->y + pz->z;
	return (r);
}
