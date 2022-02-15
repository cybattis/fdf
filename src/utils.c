/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:27:01 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/15 16:11:23 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_app(t_app *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->frame.img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	ft_free_2d((void **)fdf->map, fdf->map_size.y - 1);
	ft_free_2d((void **)fdf->screen_map, fdf->map_size.y - 1);
	ft_free_2d((void **)fdf->depth_map, WIN_H - 1);
	free(fdf);
	exit(EXIT_SUCCESS);
}

void	ft_ferror(int fd)
{
	if (fd < 0)
	{
		ft_dprintf(2, "Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	ft_error_msg(char *msg)
{
	ft_dprintf(2, "Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_free_2d(void **ptr, int i)
{
	while (i)
		free(ptr[i--]);
	free(ptr[i]);
	free(ptr);
}

void	ft_free_fdf(t_app *fdf)
{
	if (fdf->mlx && fdf->frame.img)
		mlx_destroy_image(fdf->mlx, fdf->frame.img);
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->map)
		ft_free_2d((void **)fdf->map, fdf->map_size.y - 1);
	if (fdf->screen_map)
		ft_free_2d((void **)fdf->screen_map, fdf->map_size.y - 1);
	if (fdf->depth_map)
		ft_free_2d((void **)fdf->depth_map, WIN_H - 1);
	free(fdf);
	exit(EXIT_FAILURE);
}
