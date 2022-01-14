/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/14 23:45:48 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_pixel_put_img(t_frame *frame, t_vec2 p, int color)
{
	char	*dst;

	dst = frame->addr
		+ ((int)p.y * frame->line_length + (int)p.x * (frame->bits_pp / 8));
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
