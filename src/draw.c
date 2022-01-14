/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/14 18:24:24 by cybattis         ###   ########.fr       */
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
	int		dir;
	int		dx;
	int		dy;

	v = vec2(p1.x, p1.y);
	print_vec2(p1);
	print_vec2(p2);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	dir = 1;
	if (dy < 0)
	{
		dir = -1;
		dy = -dy;
	}
	m = (2 * dy) - dx;
	ft_dprintf(2, "dy:%d | dx:%d\n", dy, dx);
	while (v.x++ < p2.x)
	{
		ft_dprintf(2, "[%d, %d]\n", v.x, v.y);
		mlx_pixel_put_img(frame, v.x, v.y, color);
		if (m > 0)
		{
			v.y += dir;
			m += 2 * (dy - dx);
		}
		else
			m += 2 * dy;
	}
}

// plotLineLow(x0, y0, x1, y1)
//     dx = x1 - x0
//     dy = y1 - y0
//     yi = 1
//     if dy < 0
//         yi = -1
//         dy = -dy
//     end if
//     D = (2 * dy) - dx
//     y = y0

//     for x from x0 to x1
//         plot(x, y)
//         if D > 0
//             y = y + yi
//             D = D + (2 * (dy - dx))
//         else
//             D = D + 2*dy
//         end if

// void lineBresenham(int x0, int y0, int x1, int y1)
// {
// int dx, dy;
// int stepx, stepy;
// dx = x1 - x0;
// dy = y1 - y0;
// if (dy < 0) { dy = -dy; stepy = -1; } else { stepy = 1; }
// if (dx < 0) { dx = -dx; stepx = -1; } else { stepx = 1; }
// dy <<= 1; /* dy is now 2*dy */
// dx <<= 1; /* dx is now 2*dx */
// if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
// theRaster[x0][y0] = 1;
// 16
// if (dx > dy) {
// int fraction = dy - (dx >> 1);
// while (x0 != x1) {
// x0 += stepx;
// if (fraction >= 0) {
// y0 += stepy;
// fraction -= dx;
// }
// fraction += dy;
// if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
// theRaster[x0][y0] = 1;
// }
// } else {
// int fraction = dx - (dy >> 1);
// while (y0 != y1) {
// if (fraction >= 0) {
// 17
// x0 += stepx;
// fraction -= dy;
// }
// y0 += stepy;
// fraction += dx;
// if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
// theRaster[x0][y0] = 1;
// }
// }
