/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:00 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/05 17:01:25 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ortho_matrix(t_vec2 screen, t_vec2 dist, t_matrix *matrix)
{
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->m[0][0] = 1 / screen.x;
	matrix->m[1][1] = 1 / screen.y;
	matrix->m[2][2] = -(2 / dist.x - dist.y);
	matrix->m[2][3] = -(dist.x + dist.y / dist.x - dist.y);
	matrix->m[3][3] = 1;
}
