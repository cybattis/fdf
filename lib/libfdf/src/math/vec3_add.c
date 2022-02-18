/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:25:17 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:29 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_vec3	*vec3_add(t_vec3 *self, t_vec3 v3)
{
	self->x += v3.x;
	self->y += v3.y;
	self->z += v3.z;
	return (self);
}