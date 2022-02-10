/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:57:26 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/10 11:10:59 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	movement(int keycode, t_fdf *fdf);
static int	option(int keycode);

int	key_hooks(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_LEFT || keycode == KEY_UP || keycode == KEY_RIGHT
		|| keycode == KEY_DOWN || keycode == KEY_Q || keycode == KEY_E)
		movement(keycode, fdf);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_image(fdf->mlx, fdf->frame.img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_all(fdf);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_F || keycode == KEY_P || keycode == KEY_F3
		|| keycode == KEY_SPACE)
		option(keycode);
	else
		printf("keycode:%d\n", keycode);
	return (0);
}

static int	movement(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_LEFT)
		fdf->t.rotation.z -= 2;
	else if (keycode == KEY_UP)
		fdf->t.rotation.x -= 2;
	else if (keycode == KEY_RIGHT)
		fdf->t.rotation.z += 2;
	else if (keycode == KEY_DOWN)
		fdf->t.rotation.x += 2;
	else if (keycode == KEY_Q)
		fdf->t.rotation.y += 2;
	else if (keycode == KEY_E)
		fdf->t.rotation.y -= 2;
	draw_frame(fdf);
	if (DEBUG == 1)
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
