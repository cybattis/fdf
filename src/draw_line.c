/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:04:26 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/15 10:46:43 by cybattis         ###   ########.fr       */
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
			//ft_printf("[%d, %d]", (int)v.y, (int)v.x);
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

// static void	draw_line_low(t_frame *frame, t_map p1, t_map p2);
// static void	draw_line_high(t_frame *frame, t_map p1, t_map p2);

// void	draw_line(t_app *fdf, t_map p1, t_map p2)
// {
// 	if (fabs(p2.v.y - p1.v.y) < fabs(p2.v.x - p1.v.x))
// 	{
// 		if (p1.v.x > p2.v.x)
// 			draw_line_low(&fdf->frame, p2, p1);
// 		else
// 			draw_line_low(&fdf->frame, p1, p2);
// 	}
// 	else
// 	{
// 		if (p1.v.y > p2.v.y)
// 			draw_line_high(&fdf->frame, p2, p1);
// 		else
// 			draw_line_high(&fdf->frame, p1, p2);
// 	}
// }

// static void	draw_line_low(t_frame *frame, t_map p1, t_map p2)
// {
// 	t_vec3	d;
// 	float	m;
// 	int		dir;

// 	d = vec3(p2.v.x - p1.v.x, p2.v.y - p1.v.y, 0.0);
// 	dir = 1;
// 	if (d.y < 0)
// 	{
// 		dir = -1;
// 		d.y = -d.y;
// 	}
// 	m = (2 * d.y) - d.x;
// 	while (p1.v.x++ < p2.v.x)
// 	{
// 		mlx_pixel_put_img(frame, p1.v.x, p1.v.y,
// 			lerp_color(p1.color, p2.color, p1.v.x, p2.v.x));
// 		if (m > 0)
// 		{
// 			p1.v.y += dir;
// 			m += 2 * (d.y - d.x);
// 		}
// 		else
// 			m += 2 * d.y;
// 	}
// }

// static void	draw_line_high(t_frame *frame, t_map p1, t_map p2)
// {
// 	t_vec3	d;
// 	float	m;
// 	int		dir;

// 	d = vec3(p2.v.x - p1.v.x, p2.v.y - p1.v.y, 0.0);
// 	dir = 1;
// 	if (d.x < 0)
// 	{
// 		dir = -1;
// 		d.x = -d.x;
// 	}
// 	m = (2 * d.x) - d.y;
// 	while (p1.v.y++ < p2.v.y)
// 	{
// 		mlx_pixel_put_img(frame, p1.v.x, p1.v.y,
// 			lerp_color(p1.color, p2.color, p1.v.y, p2.v.y));
// 		if (m > 0)
// 		{
// 			p1.v.x += dir;
// 			m += 2 * (d.x - d.y);
// 		}
// 		else
// 			m += 2 * d.x;
// 	}
// }
