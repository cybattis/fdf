/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:27:01 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/13 14:01:26 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_color(int trgb)
{
	ft_dprintf(2, "Color:%x | t:%d r:%d g:%d b:%d\n", trgb,
		get_t(trgb), get_r(trgb), get_g(trgb), get_b(trgb));
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("keycode:%d\n", keycode);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		close_win(vars);
	return (0);
}

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}
