/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:14:05 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:27 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_vec2	*vec2_divv2(t_vec2 *self, t_vec2 v2)
{
	self->x /= v2.x;
	self->y /= v2.y;
	return (self);
}

t_vec2	*vec2_divi(t_vec2 *self, long n)
{
	self->x /= n;
	self->y /= n;
	return (self);
}

t_vec2	*vec2_divf(t_vec2 *self, float n)
{
	self->x /= n;
	self->y /= n;
	return (self);
}
