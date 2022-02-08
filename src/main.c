/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:28 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/08 16:07:24 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*init_all(int argc, char *str);
static void		init_frame(t_vars *vars, t_frame *frame);

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	fdf = init_all(argc, argv[1]);

	draw_frame(fdf);
	mlx_key_hook(fdf->vars.win, key_hooks, fdf);
	mlx_loop(fdf->vars.mlx);

	free_matrix(fdf->map, fdf->map_size.y - 1);
	free(fdf);
	return (0);
}

static t_fdf	*init_all(int argc, char *str)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf) * 1);
	if (!fdf)
		exit(EXIT_FAILURE);
	fdf->screen = vec2(WIN_W, WIN_H);
	fdf->map = get_map(argc, str, &fdf->map_size);
	fdf->vars.mlx = mlx_init();
	fdf->vars.win = mlx_new_window(fdf->vars.mlx, WIN_W, WIN_H, "FdF");
	init_frame(&fdf->vars, &fdf->frame);
	fdf->t.scale = 10;
	fdf->t.rotation = vec3(30, 20, 40);
	fdf->t.translation = vec3(5, 10, 42);
	return (fdf);
}

static void	init_frame(t_vars *vars, t_frame *frame)
{
	frame->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bits_pp,
			&frame->line_length, &frame->endian);
	frame->width = WIN_W;
	frame->height = WIN_H;
}
