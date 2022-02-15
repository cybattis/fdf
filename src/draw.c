/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/15 23:14:46 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_frame(t_app *fdf)
{
	t_matrix	projection;

	clear_screen(fdf, create_trgb(0, 55, 70, 75));
	draw_circle(&fdf->frame, vec3(WIN_W / 2, WIN_H / 2, 1), 5, RED);
	world_matrix(fdf->t, &projection);
	map_projection(fdf, &projection);
	draw_map(fdf, fdf->map_size);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame.img, 0, 0);
	reset_depth_map(fdf);
	animation(fdf);
	return (0);
}

void	draw_map(t_app *fdf, t_vec2 map_size)
{
	int		i;
	int		j;

	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			if (j < map_size.x - 1)
				draw_line(fdf, fdf->screen_map[i][j],
					fdf->screen_map[i][j + 1]);
			if (i < map_size.y - 1)
				draw_line(fdf, fdf->screen_map[i][j],
					fdf->screen_map[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	clear_screen(t_app *fdf, int color)
{
	int	i;
	int	total;
	int	bytes_pp;

	i = 0;
	total = fdf->screen.x * fdf->screen.y;
	bytes_pp = fdf->frame.bits_pp / 8;
	while (i < total)
	{
		*((unsigned int *)(fdf->frame.addr + i * bytes_pp)) = color;
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

void	reset_depth_map(t_app *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			fdf->depth_map[i][j] = INT_MAX;
			j++;
		}
		i++;
	}
}
