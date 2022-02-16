/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:14:05 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:30 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_vec3	*vec3_divv3(t_vec3 *self, t_vec3 v3)
{
	self->x /= v3.x;
	self->y /= v3.y;
	self->z /= v3.z;
	return (self);
}

t_vec3	*vec3_divi(t_vec3 *self, long n)
{
	self->x /= n;
	self->y /= n;
	self->y /= n;
	return (self);
}

t_vec3	*vec3_divf(t_vec3 *self, float n)
{
	self->x /= n;
	self->y /= n;
	self->z /= n;
	return (self);
}
