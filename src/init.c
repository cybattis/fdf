/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:47:15 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/15 16:25:45 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_depth_map(t_app *fdf);
static t_map	**init_screen_map(t_app *fdf);
static void		init_window(t_app *fdf, t_frame *frame);

t_app	*init_app(int argc, char *path)
{
	t_app	*fdf;

	if (argc == 2)
	{
		fdf = ft_calloc(1, sizeof(t_app));
		if (!fdf)
			exit(EXIT_FAILURE);
		get_matrix_size(path, fdf);
		init_window(fdf, &fdf->frame);
		fdf->map = get_map(path, fdf);
		fdf->screen_map = init_screen_map(fdf);
		init_depth_map(fdf);
		fdf->def_color = WHITE;
		fdf->screen = vec2(WIN_W, WIN_H);
		fdf->t.scale = 20;
		fdf->t.rotation = vec3(238, 23, 0);
		fdf->t.translation = vec3(0.5, 0, -0.5);
		return (fdf);
	}
	ft_dprintf(2, "Error: wrong number of arguments\nUsage: ./fdf [map]\n");
	exit(EXIT_FAILURE);
}

static void	init_window(t_app *fdf, t_frame *frame)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_free_fdf(fdf);
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "FdF");
	if (!fdf->win)
	{
		free(fdf->mlx);
		ft_free_fdf(fdf);
	}
	frame->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	if (!frame->img)
		ft_free_fdf(fdf);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bits_pp,
			&frame->line_length, &frame->endian);
	if (!frame->addr)
		ft_free_fdf(fdf);
}

static t_map	**init_screen_map(t_app *fdf)
{
	int		i;
	int		j;
	t_map	**map;

	i = 0;
	map = ft_calloc(fdf->map_size.y, sizeof(t_map *));
	if (!map)
		ft_free_fdf(fdf);
	while (i < fdf->map_size.y)
	{
		j = 0;
		map[i] = ft_calloc(fdf->map_size.x, sizeof(t_map));
		if (!map[i])
		{
			ft_free_2d((void **)map, i);
			ft_free_fdf(fdf);
		}
		while (j < fdf->map_size.x)
		{
			map[i][j].color = fdf->map[i][j].color;
			j++;
		}
		i++;
	}
	return (map);
}

static void	init_depth_map(t_app *fdf)
{
	int	i;
	int	j;

	i = 0;
	fdf->depth_map = malloc(WIN_H * sizeof(float *));
	if (!fdf->depth_map)
		ft_free_fdf(fdf);
	while (i < WIN_H)
	{
		j = 0;
		fdf->depth_map[i] = malloc(WIN_W * sizeof(float));
		if (!fdf->depth_map[i])
		{
			ft_free_2d((void **)fdf->depth_map, i);
			ft_free_fdf(fdf);
		}
		while (j < WIN_W)
		{
			fdf->depth_map[i][j] = FLT_MAX;
			j++;
		}
		i++;
	}
}

void	reset_depth_map(t_app *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			fdf->depth_map[i][j] = INT_MAX;
			j++;
		}
		i++;
	}
}
