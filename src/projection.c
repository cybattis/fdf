/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/19 13:58:24 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	*matrix_mult(t_vec3 v, t_vec3 *projection)
{
	t_vec3	*p;

	p = vec3_multv3(&v, projection[0]);
	p = vec3_add(vec3_multv3(&v, projection[1]), *p);
	p = vec3_add(vec3_multv3(&v, projection[2]), *p);
	return (p);
}

t_vec3	*rotation_x(t_vec3 v, double angle)
{
	t_vec3	rx[3];

	rx[0] = vec3(1.0, 0.0, 0.0);
	rx[1] = vec3(0.0, cos(angle), -sin(angle));
	rx[2] = vec3(0.0, sin(angle), cos(angle));
	return (matrix_mult(v, rx));
}
