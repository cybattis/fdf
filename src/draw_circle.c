/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:17:32 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/16 18:32:51 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_octant(t_frame *frame, t_vec3 origin, int r, int color);
static void	draw_octant_pixel(t_frame *frame, t_vec3 o, t_vec2 p, int color);

void	draw_circle(t_frame *frame, t_vec3 origin, int r, int color)
{
	if (origin.z == 1)
	{
		while (r-- > 0)
			draw_octant(frame, origin, r, color);
		return ;
	}
	draw_octant(frame, origin, r, color);
}

static void	draw_octant(t_frame *frame, t_vec3 origin, int r, int color)
{
	t_vec2	p;
	int		d;

	p = vec2(0, r);
	d = r - 1;
	while (p.x <= p.y)
	{
		draw_octant_pixel(frame, origin, p, color);
		if (d >= 2 * p.x)
		{
			d -= 2 * p.x + 1;
			p.x++;
		}
		else if (d < 2 * (r - p.y))
		{
			d += 2 * p.y - 1;
			p.y--;
		}
		else
		{
			d += 2 * (p.y - p.x - 1);
			p.y--;
			p.x++;
		}
	}
}

static void	draw_octant_pixel(t_frame *frame, t_vec3 o, t_vec2 p, int color)
{
	mlx_pixel_put_img(frame, o.x + p.x, o.y + p.y, color);
	mlx_pixel_put_img(frame, o.x + p.y, o.y + p.x, color);
	mlx_pixel_put_img(frame, o.x - p.x, o.y + p.y, color);
	mlx_pixel_put_img(frame, o.x - p.y, o.y + p.x, color);
	mlx_pixel_put_img(frame, o.x + p.x, o.y - p.y, color);
	mlx_pixel_put_img(frame, o.x + p.y, o.y - p.x, color);
	mlx_pixel_put_img(frame, o.x - p.x, o.y - p.y, color);
	mlx_pixel_put_img(frame, o.x - p.y, o.y - p.x, color);
}
