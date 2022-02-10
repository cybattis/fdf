/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:27:01 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/10 21:22:55 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(t_fdf *fdf)
{
	free_matrix(fdf->map, fdf->map_size.y - 1);
	free_matrix(fdf->screen_map, fdf->map_size.y - 1);
	free(fdf);
}

void	ft_ferror(int fd)
{
	if (fd < 0)
	{
		ft_dprintf(2, "Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	ft_error_msg(char *msg)
{
	ft_dprintf(2, "Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

void	free_matrix(t_map **map, int i)
{
	while (i)
		free(map[i--]);
	free(map[i]);
	free(map);
}

void	strtrimr(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		str[i--] = 0;
}
