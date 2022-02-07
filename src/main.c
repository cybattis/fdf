/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:28 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/06 11:37:00 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_transform	w;
	t_vars		vars;
	t_frame		frame;
	t_map		*map;


	map = get_map(argc, argv[1]);

	w.scale = 10;
	w.rotation = vec3(30, 20, 40);
	w.translation = vec3(5, 10, 42);
	model_to_view_matrix(w, vec3(0, 0, -10));

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "FdF");
	init_frame(&vars, &frame);

	draw_frame(&vars, &frame, map);

	mlx_key_hook(vars.win, movement, &w);
	mlx_key_hook(vars.win, quit_program, &vars);
	mlx_loop(vars.mlx);

	free_matrix(map, map->size.y - 1);
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
