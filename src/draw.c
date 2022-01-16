/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/17 00:52:34 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_frame(t_vars *vars, t_frame *frame, t_vec3 **map, int size)
{
	clear_screen(frame, create_trgb(0, 55, 70, 75));
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
	draw_circle(frame, vec3(WIN_W / 2, WIN_H / 2, 1), 5, WHITE);
	draw_line(frame, vec2(200, 5), vec2(50, 150), WHITE);
	draw_map(frame, map, size);
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
}

void	draw_map(t_frame *frame, t_vec3 **map, int size)
{
	int	i;
	int	j;
	int	offsetx;
	int	offsety;

	i = 0;
	(void)map;
	offsety = (WIN_H / 2) - (size / 2);
	while (i < size)
	{
		j = 0;
		offsetx = (WIN_W / 2) - (size / 2);
		while (j < size)
		{
			mlx_pixel_put_img(frame, offsetx + i, offsety + j, WHITE);
			j++;
			offsetx += 10;
		}
		i++;
		offsety += 5;
	}
}

void	mlx_pixel_put_img(t_frame *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr
		+ (y * frame->line_length + x * (frame->bits_pp / 8));
	*(unsigned int *)dst = color;
}

void	clear_screen(t_frame *frame, int color)
{
	int	i;
	int	total;
	int	bytes_pp;

	i = 0;
	total = frame->width * frame->height;
	bytes_pp = frame->bits_pp / 8;
	while (i < total)
	{
		*((unsigned int *)(frame->addr + i * bytes_pp)) = color;
		i++;
	}
}
