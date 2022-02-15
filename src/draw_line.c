/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:04:26 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/15 16:38:22 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_app *fdf, t_map p1, t_map p2)
{
	t_vec3	v;
	t_vec3	d;
	float	step;
	int		i;

	d = vec3(p2.v.x - p1.v.x, p2.v.y - p1.v.y, p2.v.z - p1.v.z);
	if (fabs(d.x) >= fabs(d.y))
		step = fabs(d.x);
	else
		step = fabs(d.y);
	d = vec3(d.x / step, d.y / step, d.z / step);
	v = vec3(p1.v.x, p1.v.y, p1.v.z);
	i = 0;
	while (i <= step)
	{
		if (p1.color == 0)
			p1.color = fdf->def_color;
		if (p2.color == 0)
			p2.color = fdf->def_color;
		if (v.x >= 0 && v.x < WIN_W && v.y >= 0 && v.y < WIN_H)
		{
			if (v.z < fdf->depth_map[(int)v.y][(int)v.x])
			{
				mlx_pixel_put_img(&fdf->frame, v.x, v.y,
					lerp_color(p1.color, p2.color, i, step));
				fdf->depth_map[(int)v.y][(int)v.x] = (int)v.z;
			}
		}
		vec3_add(&v, d);
		i++;
	}
}

int	lerp_color(int a, int b, int i, int max)
{
	int	out;

	out = a;
	if (max > 0)
		out = create_trgb(0, ((get_r(b) - get_r(a)) * i / max + get_r(a)),
				((get_g(b) - get_g(a)) * i / max + get_g(a)),
				((get_b(b) - get_b(a)) * i / max + get_b(a)));
	return (out);
}

