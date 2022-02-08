/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:04:26 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/08 16:52:55 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_low(t_frame *frame, t_vec3 p1, t_vec3 p2, int color);
static void	draw_line_high(t_frame *frame, t_vec3 p1, t_vec3 p2, int color);

void	draw_line(t_frame *frame, t_vec3 p1, t_vec3 p2, int color)
{
	if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			draw_line_low(frame, p2, p1, color);
		else
			draw_line_low(frame, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			draw_line_high(frame, p2, p1, color);
		else
			draw_line_high(frame, p1, p2, color);
	}
}

static void	draw_line_low(t_frame *frame, t_vec3 p1, t_vec3 p2, int color)
{
	t_vec3	d;
	int		m;
	int		dir;

	d = vec3(p2.x - p1.x, p2.y - p1.y, 0.0);
	dir = 1;
	if (d.y < 0)
	{
		dir = -1;
		d.y = -d.y;
	}
	m = (2 * d.y) - d.x;
	while (p1.x++ < p2.x)
	{
		mlx_pixel_put_img(frame, p1.x, p1.y, color);
		if (m > 0)
		{
			p1.y += dir;
			m += 2 * (d.y - d.x);
		}
		else
			m += 2 * d.y;
	}
}

static void	draw_line_high(t_frame *frame, t_vec3 p1, t_vec3 p2, int color)
{
	t_vec3	d;
	int		m;
	int		dir;

	d = vec3(p2.x - p1.x, p2.y - p1.y, 0.0);
	dir = 1;
	if (d.x < 0)
	{
		dir = -1;
		d.x = -d.x;
	}
	m = (2 * d.x) - d.y;
	while (p1.y++ < p2.y)
	{
		mlx_pixel_put_img(frame, p1.x, p1.y, color);
		if (m > 0)
		{
			p1.x += dir;
			m += 2 * (d.x - d.y);
		}
		else
			m += 2 * d.x;
	}
}
