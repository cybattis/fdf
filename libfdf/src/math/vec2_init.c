/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:50:01 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:27 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_vec2	vec2(float x, float y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec2	vec2_zero(void)
{
	t_vec2	v;

	v.x = 0;
	v.y = 0;
	return (v);
}

t_vec2	vec2_set(float value)
{
	t_vec2	v;

	v.x = value;
	v.y = value;
	return (v);
}
