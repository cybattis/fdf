/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:38:47 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/12 20:49:21 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	frame;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_W, WIN_H, "FdF");
	frame.img = mlx_new_image(mlx, WIN_W, WIN_H);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel,
			&frame.line_length, &frame.endian);
	frame.width = WIN_W;
	frame.height = WIN_H;
	clear_screen(&frame, create_trgb(0, 55, 70, 75));
	mlx_put_image_to_window(mlx, mlx_win, frame.img, 0, 0);
	mlx_loop(mlx);
}
