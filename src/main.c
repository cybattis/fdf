/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:28 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/13 16:43:22 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	**init_screen_map(t_fdf *fdf);
static t_fdf	*init_all(int argc, char *str);
static void		init_frame(t_fdf *fdf, t_frame *frame);

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	fdf = init_all(argc, argv[1]);
	if (DEBUG == 1)
		draw_frame(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_hooks, fdf);
	if (DEBUG == 0)
		mlx_loop_hook(fdf->mlx, draw_frame, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

static t_fdf	*init_all(int argc, char *path)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = ft_calloc(1, sizeof(t_fdf));
		if (!fdf)
			exit(EXIT_FAILURE);
		fdf->screen = vec2(WIN_W, WIN_H);
		get_matrix_size(path, &fdf->map_size);
		if (DEBUG == 1)
			print_vec2(fdf->map_size);
		fdf->map = get_map(path, &fdf->map_size);
		fdf->screen_map = init_screen_map(fdf);
		if (DB_MATRIX == 1)
			ft_print_map(fdf->map, fdf->map_size);
		init_frame(fdf, &fdf->frame);
		fdf->def_color = WHITE;
		fdf->t.scale = 20;
		fdf->t.rotation = vec3(238, 23, 0);
		fdf->t.translation = vec3(0.5, 0, -0.5);
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

static t_map	**init_screen_map(t_fdf *fdf)
{
	int		i;
	int		j;
	t_map	**map;

	i = 0;
	map = calloc(fdf->map_size.y, sizeof(t_map *));
	if (!map)
		(exit(EXIT_FAILURE));
	while (i < fdf->map_size.y)
	{
		j = 0;
		map[i] = ft_calloc(fdf->map_size.x, sizeof(t_map));
		if (!map[i])
			exit(EXIT_FAILURE);
		while (j < fdf->map_size.x)
		{
			map[i][j].color = fdf->map[i][j].color;
			j++;
		}
		i++;
	}
	return (map);
}
