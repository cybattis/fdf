/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:57:26 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/09 18:50:21 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	movement(int keycode, t_fdf *fdf);
static int	option(int keycode);

int	key_hooks(int keycode, t_fdf *fdf)
{
	printf("keycode:%d\n", keycode);
	if (keycode == KEY_LEFT || keycode == KEY_UP
		|| keycode == KEY_RIGHT || keycode == KEY_DOWN)
		movement(keycode, fdf);
	else if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_all(fdf);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_F || keycode == KEY_P || keycode == KEY_F3
		|| keycode == KEY_SPACE)
		option(keycode);
	return (0);
}

static int	movement(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_LEFT)
	{
		fdf->t.rotation.x -= 2;
		printf("Left arrow pressed\n");
	}
	else if (keycode == KEY_UP)
	{
		fdf->t.rotation.z -= 2;
		printf("Up arrow pressed\n");
	}
	else if (keycode == KEY_RIGHT)
	{
		fdf->t.rotation.x += 2;
		printf("Right arrow pressed\n");
	}
	else if (keycode == KEY_DOWN)
	{
		fdf->t.rotation.z += 2;
		printf("Down arrow pressed\n");
	}
	draw_frame(fdf);
	print_vec3(fdf->t.rotation);
	return (0);
}

static int	option(int keycode)
{
	if (keycode == KEY_F)
		printf("F key pressed\n");
	else if (keycode == KEY_SPACE)
		printf("Space key  pressed\n");
	else if (keycode == KEY_P)
		printf("P key  pressed\n");
	else if (keycode == KEY_F3)
		printf("F3 key  pressed\n");
	return (0);
}
