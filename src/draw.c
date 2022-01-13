/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/13 17:46:35 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_pixel_put_img(t_frame *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length + x * (frame->bits_pp / 8));
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

void	draw_line(t_frame *frame, t_vec2 p1, t_vec2 p2, int color)
{
	t_vec2	v;
	int		m;
	int		step;

	v.x = p1.x;
	v.y = p1.y;
	m = 2 * ((p2.y - p1.y) - (p2.x - p1.x));
	step = 2 * (p2.y - p1.y);
	ft_dprintf(2, "[%d, %d]", v.x, v.y);
	mlx_pixel_put_img(frame, v.x, v.y, color);
	while (v.x++ < p2.x)
	{
		m += step;
		if (m >= 0)
		{
			v.y++;
			m -= 2 * (p2.x - p1.x);
		}
		ft_dprintf(2, "[%d, %d]", v.x, v.y);
		mlx_pixel_put_img(frame, v.x, v.y, color);
	}
}
