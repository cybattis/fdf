/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:04:26 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/10 20:08:35 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_frame *frame, t_vec3 p1, t_vec3 p2, int color)
{
	t_vec3	v;
	t_vec3	d;
	float	step;
	int		i;

	d.x = (p2.x - p1.x);
	d.y = (p2.y - p1.y);
	if (fabs(d.x) >= fabs(d.y))
		step = fabs(d.x);
	else
		step = fabs(d.y);
	d.x = d.x / step;
	d.y = d.y / step;
	v.x = p1.x;
	v.y = p1.y;
	i = 0;
	while (i <= step)
	{
		if (v.x >= 0 && v.x <= WIN_W && v.y >= 0 && v.y <= WIN_H)
			mlx_pixel_put_img(frame, v.x, v.y, color);
		v.x += d.x;
		v.y += d.y;
		i++;
	}
}

// static void	draw_line_low(t_frame *frame, t_vec3 p1, t_vec3 p2, int color);
// static void	draw_line_high(t_frame *frame, t_vec3 p1, t_vec3 p2, int color);

// void	draw_line(t_frame *frame, t_vec3 p1, t_vec3 p2, int color)
// {
// 	if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x))
// 	{
// 		if (p1.x > p2.x)
// 			draw_line_low(frame, p2, p1, color);
// 		else
// 			draw_line_low(frame, p1, p2, color);
// 	}
// 	else
// 	{
// 		if (p1.y > p2.y)
// 			draw_line_high(frame, p2, p1, color);
// 		else
// 			draw_line_high(frame, p1, p2, color);
// 	}
// }

// static void	draw_line_low(t_frame *frame, t_vec3 p1, t_vec3 p2, int color)
// {
// 	t_vec3	d;
// 	float	m;
// 	int		dir;

// 	d = vec3(p2.x - p1.x, p2.y - p1.y, 0.0);
// 	dir = 1;
// 	if (d.y < 0)
// 	{
// 		dir = -1;
// 		d.y = -d.y;
// 	}
// 	m = (2 * d.y) - d.x;
// 	while (p1.x++ < p2.x)
// 	{
// 		mlx_pixel_put_img(frame, p1.x, p1.y, color);
// 		if (m > 0)
// 		{
// 			p1.y += dir;
// 			m += 2 * (d.y - d.x);
// 		}
// 		else
// 			m += 2 * d.y;
// 	}
// }

// static void	draw_line_high(t_frame *frame, t_vec3 p1, t_vec3 p2, int color)
// {
// 	t_vec3	d;
// 	float	m;
// 	int		dir;

// 	d = vec3(p2.x - p1.x, p2.y - p1.y, 0.0);
// 	dir = 1;
// 	if (d.x < 0)
// 	{
// 		dir = -1;
// 		d.x = -d.x;
// 	}
// 	m = (2 * d.x) - d.y;
// 	while (p1.y++ < p2.y)
// 	{
// 		mlx_pixel_put_img(frame, p1.x, p1.y, color);
// 		if (m > 0)
// 		{
// 			p1.x += dir;
// 			m += 2 * (d.x - d.y);
// 		}
// 		else
// 			m += 2 * d.x;
// 	}
// }
