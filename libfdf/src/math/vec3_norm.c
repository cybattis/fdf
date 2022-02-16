/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:23:19 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:18 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <math.h>

t_vec3	*vec3_normalize(t_vec3 *self)
{
	return (vec3_divf(self, vec3_mag(*self)));
}

t_vec3	vec3_normalized(t_vec3 v)
{
	float	mag;

	mag = vec3_mag(v);
	return (vec3(v.x / mag, v.y / mag, v.z / mag));
}

float	vec3_mag(t_vec3 v)
{
	return (fabs(sqrt(v.x * v.x + v.y * v.y + v.z * v.z)));
}
