/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:30:19 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/04 10:29:20 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	add_shade(float distance, int trgb)
{
	print_color(trgb);
	trgb *= distance;
	print_color(trgb);
	return (trgb);
}

int	get_opposite(int trgb)
{
	return (trgb ^ 0x7fffffff);
}
