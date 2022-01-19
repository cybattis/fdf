/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:04:26 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/19 18:38:29 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_low(t_frame *frame, t_vec3 v1, t_vec3 v2, int color);
static void	draw_line_high(t_frame *frame, t_vec3 v1, t_vec3 v2, int color);

void	draw_line(t_frame *frame, t_vec3 v1, t_vec3 v2, int color)
{
	if (fabs(v2.y - v1.y) < fabs(v2.x - v1.x))
	{
		if (v1.x > v2.x)
			draw_line_low(frame, v2, v1, color);
		else
			draw_line_low(frame, v1, v2, color);
	}
	else
	{
		if (v1.y > v2.y)
			draw_line_high(frame, v2, v1, color);
		else
			draw_line_high(frame, v1, v2, color);
	}
}

static void	draw_line_low(t_frame *frame, t_vec3 v1, t_vec3 v2, int color)
{
	t_vec3	d;
	int		m;
	int		dir;

	d = vec3(v2.x - v1.x, v2.y - v1.y, 0.0);
	dir = 1;
	if (d.y < 0)
	{
		dir = -1;
		d.y = -d.y;
	}
	m = (2 * d.y) - d.x;
	while (v1.x++ < v2.x)
	{
		mlx_pixel_put_img(frame, v1.x, v1.y, color);
		if (m > 0)
		{
			v1.y += dir;
			m += 2 * (d.y - d.x);
		}
		else
			m += 2 * d.y;
	}
}

static void	draw_line_high(t_frame *frame, t_vec3 v1, t_vec3 v2, int color)
{
	t_vec3	d;
	int		m;
	int		dir;

	d = vec3(v2.x - v1.x, v2.y - v1.y, 0.0);
	dir = 1;
	if (d.x < 0)
	{
		dir = -1;
		d.x = -d.x;
	}
	m = (2 * d.x) - d.y;
	while (v1.y++ < v2.y)
	{
		mlx_pixel_put_img(frame, v1.x, v1.y, color);
		if (m > 0)
		{
			v1.x += dir;
			m += 2 * (d.x - d.y);
		}
		else
			m += 2 * d.x;
	}
}
