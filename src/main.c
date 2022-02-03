/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:28 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/03 14:55:50 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	size_t	map_size;
	t_vars	vars;
	t_frame	frame;
	t_vec3	**map;

	map_size = get_matrix_size(argc, argv[1]);
	map = init_map(argv[1], map_size);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "FdF");

	init_frame(&vars, &frame);
	draw_frame(&vars, &frame, map, map_size);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

	free_matrix(map, map_size - 1);
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
