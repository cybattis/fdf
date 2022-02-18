/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:58:07 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:30 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <math.h>

t_vec3	vec3(float x, float y, float z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	vec3_zero(void)
{
	t_vec3	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}

t_vec3	vec3_set(float value)
{
	t_vec3	v;

	v.x = value;
	v.y = value;
	v.z = value;
	return (v);
}
