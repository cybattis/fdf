/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/10 21:22:46 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_frame(t_fdf *fdf)
{
	t_matrix	projection;

	clear_screen(fdf, create_trgb(0, 55, 70, 75));
	draw_circle(&fdf->frame, vec3(WIN_W / 2, WIN_H / 2, 1), 5, RED);
	world_matrix(fdf->t, &projection);
	if (DEBUG == 1)
	{
		ft_dprintf(2, "\nWorld projection\n");
		print_matrix44(projection.m);
		ft_dprintf(2, "\n");
	}
	map_projection(fdf, &projection);
	draw_map(fdf, fdf->map_size);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame.img, 0, 0);
	return (0);
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
			if (fdf->screen_map[i][j].color == 0)
				fdf->screen_map[i][j].color = WHITE;
			if (j < map_size.x - 1)
				draw_line(&fdf->frame, fdf->screen_map[i][j].v,
					fdf->screen_map[i][j + 1].v, fdf->screen_map[i][j].color);
			if (i < map_size.y - 1)
				draw_line(&fdf->frame, fdf->screen_map[i][j].v,
					fdf->screen_map[i + 1][j].v, fdf->screen_map[i][j].color);
			j++;
		}
		i++;
	}
}

void	clear_screen(t_fdf *fdf, int color)
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
