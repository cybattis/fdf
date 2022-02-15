/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:28 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/15 14:41:32 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_app	*fdf;

	fdf = init_app(argc, argv[1]);
	mlx_hook(fdf->win, 4, 0, mouse_hooks, fdf);
	mlx_hook(fdf->win, 17, 0, close_app, fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_hooks, fdf);
	mlx_loop_hook(fdf->mlx, draw_frame, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
