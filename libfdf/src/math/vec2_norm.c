/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:26:34 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:28 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <math.h>

t_vec2	*vec2_normalize(t_vec2 *self)
{
	return (vec2_divf(self, vec2_mag(*self)));
}

t_vec2	vec2_normalized(t_vec2 v)
{
	float	mag;

	mag = vec2_mag(v);
	return (vec2(v.x / mag, v.y / mag));
}

float	vec2_mag(t_vec2 v)
{
	return (fabs(sqrt(v.x * v.x + v.y * v.y)));
}
