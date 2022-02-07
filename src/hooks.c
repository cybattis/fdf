/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:57:26 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/06 11:37:41 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	quit_program(int keycode, t_vars *vars)
{
	printf("keycode:%d\n", keycode);
	if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_LEFT)
		printf("Left arrow pressed\n");
	else if (keycode == KEY_UP)
		printf("Up arrow pressed\n");
	else if (keycode == KEY_RIGHT)
		printf("Right arrow pressed\n");
	else if (keycode == KEY_DOWN)
		printf("Down arrow pressed\n");
	return (0);
}

int	movement(int keycode, t_transform w)
{
	return (0);
}
