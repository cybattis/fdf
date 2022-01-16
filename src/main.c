/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:28 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/16 18:35:30 by cybattis         ###   ########.fr       */
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
