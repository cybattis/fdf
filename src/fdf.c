/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:38:47 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/14 23:24:15 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_vars	vars;
	t_frame	frame;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "FdF");
	init_frame(&vars, &frame);
	draw_frame(&vars, &frame);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	init_frame(t_vars *vars, t_frame *frame)
{
	frame->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bits_pp,
			&frame->line_length, &frame->endian);
	frame->width = WIN_W;
	frame->height = WIN_H;
}

void	draw_frame(t_vars *vars, t_frame *frame)
{
	t_vec2	p2 = {200, 5};
	t_vec2	p1 = {50, 150};

	clear_screen(frame, create_trgb(0, 55, 70, 75));
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
	mlx_pixel_put_img(frame, p1.x, p1.y, WHITE);
	mlx_pixel_put_img(frame, p2.x, p2.y, WHITE);
	draw_line(frame, p1, p2, WHITE);
	mlx_put_image_to_window(vars->mlx, vars->win, frame->img, 0, 0);
}
