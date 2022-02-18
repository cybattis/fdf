/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:58:54 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:27 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_vec2	*vec2_multv2(t_vec2 *self, t_vec2 v2)
{
	self->x = self->x * v2.x;
	self->y = self->y * v2.y;
	return (self);
}

t_vec2	*vec2_multi(t_vec2 *self, long n)
{
	self->x = self->x * n;
	self->y = self->y * n;
	return (self);
}

t_vec2	*vec2_multf(t_vec2 *self, float n)
{
	self->x = self->x * n;
	self->y = self->y * n;
	return (self);
}
