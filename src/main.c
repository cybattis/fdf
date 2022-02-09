/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:28 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/09 16:23:14 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*init_all(int argc, char *str);
static void		init_frame(t_fdf *fdf, t_frame *frame);

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	fdf = init_all(argc, argv[1]);
	mlx_key_hook(fdf->win, key_hooks, fdf);
	mlx_loop_hook(fdf->mlx, draw_frame, fdf);
	mlx_loop(fdf->mlx);
	free_matrix(fdf->map, fdf->map_size.y - 1);
	free(fdf);
	return (0);
}

static t_fdf	*init_all(int argc, char *path)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = malloc(sizeof(t_fdf) * 1);
		if (!fdf)
			exit(EXIT_FAILURE);
		ft_memset(fdf, 0, sizeof(t_fdf));
		fdf->screen = vec2(WIN_W, WIN_H);
		get_matrix_size(path, &fdf->map_size);
		fdf->map = get_map(path, &fdf->map_size);
		if (DEBUG == 1)
		{
			print_vec2(fdf->map_size);
			ft_print_map(fdf->map, fdf->map_size);
		}
		init_frame(fdf, &fdf->frame);
		fdf->t.scale = 20;
		fdf->t.rotation = vec3(35, 0, 35);
		fdf->t.translation = vec3(0, 0, 0);
		return (fdf);
	}
	ft_dprintf(2, "Error: wrong number of arguments\nUsage: ./fdf [map]\n");
	exit(EXIT_FAILURE);
}

static void	init_frame(t_fdf *fdf, t_frame *frame)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "FdF");
	frame->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bits_pp,
			&frame->line_length, &frame->endian);
}
