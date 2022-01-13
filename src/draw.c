/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/13 14:14:03 by cybattis         ###   ########.fr       */
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
