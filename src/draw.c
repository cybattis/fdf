/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/06 11:18:10 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_frame(t_vars *vars, t_frame *frame, t_map *map)
{
	clear_screen(frame, create_trgb(0, 55, 70, 75));
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
	draw_circle(frame, vec3(WIN_W / 2, WIN_H / 2, 1), 5, RED);
	// update_map(map, map);
	// draw_map(frame, map);
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
}

void	draw_map(t_frame *frame, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (j < map->size.x)
		{
			if (j < map->size.x - 1)
				draw_line(frame, map->v[i][j], map->v[i][j + 1], WHITE);
			if (i < map->size.y - 1)
				draw_line(frame, map->v[i][j], map->v[i + 1][j], WHITE);
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
