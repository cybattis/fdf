/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/19 13:46:43 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_frame(t_vars *vars, t_frame *frame, t_vec3 **map, int size)
{
	clear_screen(frame, create_trgb(0, 55, 70, 75));
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
	draw_line(frame, vec2(200, 5), vec2(50, 150), WHITE);
	draw_map(frame, map, size);
	draw_circle(frame, vec3(WIN_W / 2, WIN_H / 2, 1), 5, RED);
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
}

void	draw_map(t_frame *frame, t_vec3 **map, int size)
{
	int		i;
	int		j;
	t_vec3	*p;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			p = rotation_x(map[i][j], 0.03);
			mlx_pixel_put_img(frame, p->x, p->y, WHITE);
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
