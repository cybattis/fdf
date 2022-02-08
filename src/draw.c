/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/08 16:56:02 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_frame(t_fdf *fdf)
{
	t_matrix	projection;

	clear_screen(&fdf->frame, create_trgb(0, 55, 70, 75));
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->frame.img, 0, 0);
	draw_circle(&fdf->frame, vec3(WIN_W / 2, WIN_H / 2, 1), 5, RED);
	screen_projection(fdf, &projection);
	map_projection(fdf, &projection);
	draw_map(fdf, fdf->map_size);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->frame.img, 0, 0);
}

void	draw_map(t_fdf *fdf, t_vec2 map_size)
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
				draw_line(&fdf->frame, fdf->map[i][j].v, fdf->map[i][j + 1].v, WHITE);
			if (i < map_size.y - 1)
				draw_line(&fdf->frame, fdf->map[i][j].v, fdf->map[i + 1][j].v, WHITE);
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
