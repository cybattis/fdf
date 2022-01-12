/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:27:01 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/12 15:30:06 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_color(int trgb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_t(trgb);
	r = get_r(trgb);
	g = get_g(trgb);
	b = get_b(trgb);
	ft_dprintf(2, "Update: %d %d %d %d\n", t, r, g, b);
	return (0);
}
