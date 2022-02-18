/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lerpf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:48:57 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:31 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <math.h>

t_vec3	vec3_lerpf(t_vec3 base, t_vec3 high, float value)
{
	t_vec3	v;

	v.x = ft_lerp(base.x, high.x, value);
	v.y = ft_lerp(base.y, high.y, value);
	v.z = ft_lerp(base.z, high.z, value);
	return (v);
}
