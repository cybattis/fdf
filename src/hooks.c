/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:57:26 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/15 14:42:51 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	translation(int keycode, t_app *fdf);
static int	movement(int keycode, t_app *fdf);
static int	option(int keycode);

int	mouse_hooks(int mousecode, int x, int y, t_app *fdf)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		fdf->t.scale += 0.5;
	else if (mousecode == 5)
		fdf->t.scale -= 0.5;
	else
		ft_printf("mousecode:%d\n", mousecode);
	return (0);
}

int	key_hooks(int keycode, t_app *fdf)
{
	if (keycode == KEY_LEFT || keycode == KEY_UP || keycode == KEY_RIGHT
		|| keycode == KEY_DOWN || keycode == KEY_Q || keycode == KEY_E
		|| keycode == KEY_X || keycode == KEY_Z)
		movement(keycode, fdf);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D)
		translation(keycode, fdf);
	else if (keycode == KEY_F || keycode == KEY_P || keycode == KEY_F3
		|| keycode == KEY_SPACE)
		option(keycode);
	else if (keycode == KEY_ESC)
		close_app(fdf);
	else
		ft_printf("keycode:%d\n", keycode);
	return (0);
}

static int	movement(int keycode, t_app *fdf)
{
	if (keycode == KEY_LEFT)
		fdf->t.rotation.y += 1;
	else if (keycode == KEY_RIGHT)
		fdf->t.rotation.y -= 1;
	else if (keycode == KEY_UP)
		fdf->t.rotation.x -= 1;
	else if (keycode == KEY_DOWN)
		fdf->t.rotation.x += 1;
	else if (keycode == KEY_Q)
		fdf->t.rotation.z -= 1;
	else if (keycode == KEY_E)
		fdf->t.rotation.z += 1;
	else if (keycode == KEY_Z)
		fdf->t.scale += 0.5;
	else if (keycode == KEY_X)
		fdf->t.scale -= 0.5;
	return (0);
}

static int	option(int keycode)
{
	if (keycode == KEY_F)
		ft_printf("F key pressed\n");
	else if (keycode == KEY_SPACE)
		ft_printf("Space key pressed\n");
	else if (keycode == KEY_P)
		ft_printf("P key pressed\n");
	else if (keycode == KEY_F3)
		ft_printf("F3 key pressed\n");
	return (0);
}

static int	translation(int keycode, t_app *fdf)
{
	if (keycode == KEY_W)
		fdf->t.translation.z += 1;
	else if (keycode == KEY_S)
		fdf->t.translation.z -= 1;
	else if (keycode == KEY_A)
		fdf->t.translation.x -= 1;
	else if (keycode == KEY_D)
		fdf->t.translation.x += 1;
	return (0);
}
