/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/01 14:06:19 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_frame(t_vars *vars, t_frame *frame, t_vec3 **map, int size)
{
	clear_screen(frame, create_trgb(0, 55, 70, 75));
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
	// draw_circle(frame, vec3(OX, OY, 1), 1, RED);
	update_map(map, size);
	draw_map(frame, map, size);
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
}

void	draw_map(t_frame *frame, t_vec3 **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j < size - 1)
				draw_line(frame, map[i][j], map[i][j + 1], WHITE);
			if (i < size - 1)
				draw_line(frame, map[i][j], map[i + 1][j], WHITE);
			j++;
		}
		i++;
	}
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

void	mlx_pixel_put_img(t_frame *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr
		+ (y * frame->line_length + x * (frame->bits_pp / 8));
	*(unsigned int *)dst = color;
}
